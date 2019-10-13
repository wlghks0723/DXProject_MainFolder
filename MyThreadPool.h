#pragma once
#define g_ThreadPool ThreadPool::GetInstance()
class ThreadPool {
private:
	static ThreadPool* Inst;
public:
	static ThreadPool* GetInstance()
	{
		if (Inst == NULL) Inst = new ThreadPool(10);
		return Inst;
	}
public:
	ThreadPool(std::size_t num_threads);
	~ThreadPool();

	// job �� �߰��Ѵ�.
	template <class F, class... Args>
	std::future<typename std::result_of<F(Args...)>::type> EnqueueJob(THREADMENU eState,
		F&& f, Args&&... args);

	void Thread_Stop(THREADMENU eState)
	{
		if (m_worker_threads_[eState].joinable())
			m_worker_threads_[eState].detach();
	}

private:
	// �� Worker �������� ����.
	std::size_t m_num_threads_;
	// Worker �����带 �����ϴ� ����.
	std::vector<std::thread> m_worker_threads_;
	// ���ϵ��� �����ϴ� job ť.
	std::deque<std::function<void()>> m_jobs_;
	// ���� job ť�� ���� cv �� m.
	std::condition_variable m_cv_job_q_;
	std::mutex m_job_q_;

	// ��� ������ ����
	bool m_stop_all;
	void StopThraed(THREADMENU eState);
	// Worker ������
	void WorkerThread();
};




template <class F, class... Args>
std::future<typename std::result_of<F(Args...)>::type> ThreadPool::EnqueueJob(THREADMENU eState,
	F&& f, Args&&... args) {
	if (m_stop_all) {
		throw std::runtime_error("ThreadPool ��� ������");
	}
	using return_type = typename std::result_of<F(Args...)>::type;
	auto job = std::make_shared<std::packaged_task<return_type()>>(
		std::bind(std::forward<F>(f), std::forward<Args>(args)...));

	std::future<return_type> job_result_future = job->get_future();
	{
		std::lock_guard<std::mutex> lock(m_job_q_);
		m_jobs_.push_front([job]() { (*job)(); });
	}
	m_cv_job_q_.notify_one();

	//������Ʈ�� ������Ű�� �ٽ��Ҵ��Ѵ�.
	if(m_worker_threads_[eState].joinable())
		m_worker_threads_[eState].detach();
	
	m_worker_threads_[eState] = thread(([this]() { this->WorkerThread(); }));
	
	return job_result_future;
}




