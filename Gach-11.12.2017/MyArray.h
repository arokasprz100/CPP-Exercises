#ifndef MyArray_h
#define MyArray_h

class MyArray 
{
public:
	MyArray (int startSize);
	MyArray (const MyArray& copied);
	int& at(int index) const;
	void print() const;
	void resize (int newSize);
	~MyArray();


	const int& size;

private:
	int * m_arrayOfInts;
	int m_size;


};

#endif