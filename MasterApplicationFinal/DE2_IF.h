#pragma once
class DE2_IF
{
public:
	DE2_IF();
	void resetI();
	bool signalUnlocked() const;
	bool getAllowPrint() const;
	void setAllowPrint(bool);
	int getI() const;
	void setI();
private:
	bool Allowprint_;
	int i_;
};

