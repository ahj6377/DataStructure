
#include <iostream>
using namespace std;

#define maxQueue 31


/**
*	@brief	Exception class thrown by Enqueue when queue is full.
*/
class FullQueue
{
public:
	/**
	*	@brief	Display a message for full queue on screen.
	*/
	void print()
	{
		cout << "FullQueue exception thrown." << endl;
	}
};


/**
*	@brief	Exception class thrown by Dequeue when queue is empty.
*/
class EmptyQueue
{
public:
	/**
	*	@brief	Display a message for empty queue on screen.
	*/
	void print()
	{
		cout << "EmtpyQueue exception thrown." << endl;
	}
};

/**
*	@brief	Queue class. 과제 1에서 이 클래스는 쓰이지 않는다.
*	@details	This class processes as First In, First Out (FIFO), 템플릿을 적용해 다양한 변수 타입을 저장할 수 있다.
*/
template <typename T>
class CircularQueueType
{
public:
	/**
	*	@brief	Allocate dynamic array whose size is maxQueue.
	*	@pre	The maxQueue is defined
	*	@post	Member of items points the allocated array.
	*/
	CircularQueueType();

	/**
	*	@brief	Allocate dynamic array whose size is max.
	*	@pre	none.
	*	@post	Member of items points the allocated array.
	*/
	CircularQueueType(int max);

	/**
	*	@brief	Destruct the object. Free the array dynamically allocated.
	*	@pre	Release memory for queue pointer.
	*	@post	none.
	*/
	~CircularQueueType();


	/**
	*	@brief	Determines whether the queue is full.
	*	@pre	Queue has been initialized.
	*	@post	Function value = (queue is full)
	*/
	bool IsFull();

	/**
	*	@brief	Determines whether the queue is empty.
	*	@pre	Queue has been initialized.
	*	@post	Function value = (queue is empty)
	*/
	bool IsEmpty();

	/**
	*	@brief	Makes the queue empty.
	*	@pre	Queue has been initialized.
	*	@post	m_iFront와 m_iRear is set same value as Constructer.
	*/
	void MakeEmpty();

	/**
	*	@brief	Adds newItem to the last of the queue.
	*	@pre	Queue has been initialized.
	*	@post	If (queue is full), FullQueue exception is thrown; otherwise, newItem is at the last.
	*/
	void EnQueue(T item);

	/**
	*	@brief	Removes first item from the queue.
	*	@pre	Queue has been initialized.
	*	@post	If (queue is empty), EmptyQueue exception is thrown; otherwise, first element has been removed from queue. item gets value of removed item.
	*/
	void DeQueue(T &item);

	/**
	*	@brief	Print all the items in the queue on screen
	*	@pre	Queue has been initialized.
	*	@post	None.
	*/
	void Print();
	/**
	*	@brief	Queue의 iterator을 초기화한다.
	*	@pre	없다.
	*	@post	Quere의 iterator가 초기화된다.
	*/
	void ResetQueue()
	{
		m_iCurPointer = m_iRear;
	}
	/**
	*	@brief	Queue의 다음 레코드를 받아오고 iterator을 하나 감소시킨다.
	*	@pre	큐 안의 데이터와 큐가 초기화되어있어야한다.
	*	@post	다음 레코드가 data에 저장되고, m_iCurPointer가 1 줄어든다.
	*	@return		end of Quere일경우 -1, 그외의 경우엔 m_iCurPointer
	*	@param	data 데이터 타입
	*/
	int	GetNextitem(T& data)
	{
		m_iCurPointer--;
		m_iCurPointer = m_iCurPointer % m_nMaxQueue;
		if (m_iCurPointer == m_iFront)	//end of Quere면
			return -1;		//-1을 리턴
		if (m_iCurPointer != -1)
		{
			if (IsEmpty())
				throw EmptyQueue();
			else
				data = m_pItems[m_iCurPointer];
		}

		return m_iCurPointer;
	}	
	/**
	*	@brief	Queue의 현재 레코드를 받아온다
	*	@pre	큐 안의 데이터와 큐가 초기화되어있어야한다.
	*	@post	없다.
	*	@return	없다.
	*	@param	data 데이터 타입
	*/
	void GetCurrentitem(T& data)
	{
		data = m_pItems[m_iCurPointer];
	}
	
private:
	int m_iCurPointer;		//iterator
	int m_iFront;	//index of one infront of the first element.
	int m_iRear;	//index of the last element.
	int m_nMaxQueue;	//max size of the queue.
	T* m_pItems;	//pointer for dynamic allocation.
};

//Allocate dynamic array whose size is maxQueue.
template <typename T>
CircularQueueType<T>::CircularQueueType()
{
	m_pItems=new T[maxQueue];	//m_pItems에 크기가 maxQueue인 배열을 만든다.
	m_nMaxQueue=maxQueue;
	m_iFront=m_nMaxQueue-1;
	m_iRear=m_nMaxQueue-1;	//멤버 변수들을 초기화시켜준다.
}

//Allocate dynamic array whose size is max.
template <typename T>
CircularQueueType<T>::CircularQueueType(int max)
{	
	
	m_pItems=new T[max];	//m_pItems에 크기가 max인 배열을 만든다.
	m_nMaxQueue=max;
	m_iFront=m_nMaxQueue-1;
	m_iRear=m_nMaxQueue-1;	//멤버 변수들을 초기화시켜준다.
}

//Destruct the object. Free the array dynamically allocated.
template <typename T>
CircularQueueType<T>::~CircularQueueType()
{
	delete[] m_pItems;	//동적할당했던 메모리를 해제해준다.
}

//Determines whether the queue is full.
template <typename T>
bool CircularQueueType<T>::IsFull()
{
	if(m_iFront-m_iRear==1||m_iRear-m_iFront==m_nMaxQueue-1)
		return 1;	//m_iFront가 m_iRear보다 1 앞일때는 꽉 찬것이므로 1을 리턴한다. m_iFront가 0일때는 m_iRear가 m_nMaxQueue-1과 같을때 꽉 찬것이다.
	return 0;	//꽉 차지 않았으면 0을 리턴한다.
}

//Determines whether the queue is empty.
template <typename T>
bool CircularQueueType<T>::IsEmpty()
{
	if(m_iFront==m_iRear)
		return 1;	//m_iFront와 m_iRear가 같은 경우는 queue가 비어있는 상태이므로 1을 리턴한다.
	return 0;	//비어있지 않으면 0을 리턴한다.
}

//Makes the queue empty.
template <typename T>
void CircularQueueType<T>::MakeEmpty()
{
	m_iFront=m_nMaxQueue-1;
	m_iRear=m_nMaxQueue-1;	//생성자와 같은 값으로 m_iFront와 m_iRear를 변경해준다.
}

//Adds newItem to the last of the queue.
template <typename T>
void CircularQueueType<T>::EnQueue(T item)
{
	if(IsFull())
		throw FullQueue();	//꽉 찼을땐 throw FullQueue
	m_iRear=(m_iRear+1)%m_nMaxQueue;
	m_pItems[m_iRear]=item;	//m_iRear를 1증가시켜주고 item값을 넣어준다.
}

//Removes first item from the queue.
template <typename T>
void CircularQueueType<T>::DeQueue(T& item)
{
	if(IsEmpty())
		throw EmptyQueue();	//비어있을땐 throw EmptyQueue
	m_iFront=(m_iFront+1)%m_nMaxQueue;
	item=m_pItems[m_iFront];	//m_iFront를 1 증가시켜주고 삭제될 값을 item에 복사해준다.
}
