#pragma once
class DataStructure
{
	public: 
		virtual int GetSize() { return size; };
		virtual void SetSize(int n) { size = n; };
		virtual double GetAverage() = 0;
	private:
		int size;
};