#ifndef MENGINE_HPP
#define MENGINE_HPP

class mCore
{
public:
    mCore();
	virtual ~mCore();
	
	void Run();
	void InitGame();
	
	void ProcessFrame();

    bool IsRunning() const;
    void DoExit();
	
private:
	
	// pointer for subsystems

    bool run;
};

#endif // MENGINE_HPP
