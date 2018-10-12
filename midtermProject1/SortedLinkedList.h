#pragma once


template <typename T>
struct NodeType {
	T data; //각 노드의 데이터
	NodeType* next;// 노드의 다음을 가리킬 포인터


};


template<typename T>
class SortedLinkedList
{
public:
	/**
*	default constructor.
*/
	SortedLinkedList();

	/**
	*	destructor.
	*/
	~SortedLinkedList();
	/**
	*	@brief	깊은 복사를 위한 SortedLinkedList의 복사 연산자
	*	@pre	anotherList가 초기화되어 있어야한다.
	*	@post	anotherList와 같은 정보를 가진 리스트가 생성된다
	*	@param	anotherList 복사하고자 하는 SortedLinkedList
	*/
	SortedLinkedList(const SortedLinkedList<T>& anotherList);		
	/**
	*	@brief	링크드 리스트의 모든 노드를 제거한다.
	*	@pre	None.
	*	@post	리스트가 비워진다.
	
	*/
	void MakeEmpty();

	/**
	*	@brief	리스트의 길이 = 원소의 개수 를 리턴함
	*	@pre	x
	*	@post	리턴값이 리스트의 길이가 된다
	*	@return	리스트의 길이 = 원소의 개수
	*/
	int GetLength()
	{
		return m_nLength;
	}
	/**
	*	@brief	새로운 노드의 값을 비교하여 맞는 위치에 추가한다
	*	@pre	List is not Full(메모리에 빈 공간이 있어야 한다)
	*	@post	리스트에 아이템이 추가된다.
	*	@return	추가되면 1 아니면 0
	*	@param 추가하고자 하는 데이터값
	*/
	int Add(T& data);
	/**
	*	@brief	입력한 정보와 같은 정보를 가진 리스트의 원소를 리스트에서 삭제한다
	*	@pre	리스트가 비어있지 않아야한다.
	*	@post	리스트의 원소가 삭제되고 길이가 짧아진다.
	*	@return	삭제됬으면 1 아니면 0
	*	@param data 삭제하고자 하는 데이터값
	*/
	int Delete(T& data);
	/**
	*	@brief	리스트내의 정보를 바꾼다
	*	@pre	리스트에 하나이상의 원소가 있어야한다.
	*	@post	리스트내의 원소의 정보가 바뀐다
	*	@return	작동했으면 1 아니면 0
	*/
	int Replace(T& data);
	/**
	*	@brief	리스트에서 Primarykey를 기준으로 일치하는 원소를 받아온다
	*	@pre	리스트내의 정보가 초기화되있어야 한다
	*	@post	키와 맞는 정보가 있으면 그것을 받아온다..
	*	@return	찾아왔으면 1, 못찾았으면 0
	*/
	int Get(T& item);
	/**
	*	@brief	m_pCurPointer을 맨 앞위치로 초기화한다.
	*	@pre	None.
	*	@post	current pointer is prior to list. current pointer has been initialized.
	*/
	void ResetList();
	/**
	*	@brief	리스트내의 다음 원소를 받아온다.
	*	@pre	현재 원소가 마지막이 아니어야하고, CurPointer가 정의되어야한다.
	*	@post	CurPointer의 위치가 다음위치로 가고 다음위치의 값이 리턴된다.
	*/
	void GetNextItem(T& data);

	/**
	*	@brief	리스트가 비어있는지를 확인한다.
	*	@pre	x
	*	@post	x
	*	@return 비었으면 1, 아니면 0
	*/
	bool IsEmpty()
	{
		if (m_nLength == 0)
			return true;
		else
			return false;
	}
	/**
	*	@brief	Curpointer을 다음으로 옮긴다.
	*	@pre	m_pCurPointer가 정의되어 있어야한다.
	*	@post	x
	*/
	void GotoNextItem()
	{				
		
		m_pCurPointer = m_pCurPointer->next;
	}
	/**
	*	@brief	리스트내의 현재 원소를 받아온다.
	*	@pre	리스트에 하나이상의 원소가 있으며 CurPointer가 정의되어야한다.
	*	@post	data에 현위치의 값이 받아진다.
	*/
	void GetCuritem(T& data);
	/**
*	@brief	리스트내의 iterator가 마지막을 가리키는가?
*	@pre	m_pCurPointer ResetList를 통해 NULL을 가리키면 안된다.
*	@post	x
*	@return	리스트의 마지막을 가리키면 1 아니면 0
*/
	bool IsLastPointer_NotResetList()    
	{
		if (m_pCurPointer == NULL)   // m_p_CurPointer가 NULL일땐 리스트의 끝이다
			return true;
		else
			return false;
	}

	/**
	*	@brief	리스트의 head에 해당하는 데이터를 가져옴
	*	@pre	리스트가 초기화 되어 있어야 함.
	*	@post	head에 해당하는 데이터를 가져옴
	*/
	int GetFirstItem(T& item);
	/**
	*	@brief	m_pCurPointer가 가리키는 data의 주소를 받아온다.
	*	@pre	m_PCurPotiner가 정의되어 있어야한다.
	*	@post	x
	*	@return m_pCurPointer가 가리키는 data의 주소값
	*/
	T* GetCurItemAddress()
	{
		// m_pCurPointer가 NULL이라면 처음 node를 가리킴.
		if (m_pCurPointer == NULL)
		{
			m_pCurPointer = m_pList;
		}
		
		return &(m_pCurPointer->data);
	}
	/**
	*	@brief	복사 생성자를 이용한 대입 연산자
	*	@pre	anotherList가 정의되어 있어야한다.
	*	@post	깊은 복사된 리스트가 대입된다.
	*	@return 복사된 리스트
	*/
	SortedLinkedList<T> operator=(const SortedLinkedList<T> &anotherList);

private:
	NodeType<T> *m_pList;
	NodeType<T> *m_pCurPointer;
	int m_nLength;
};



//함수 정의부
template<typename T>
SortedLinkedList<T>::SortedLinkedList()
{
	m_nLength = 0;
	m_pList = NULL;
	m_pCurPointer = NULL;

}
template<typename T>
SortedLinkedList<T>::~SortedLinkedList()
{
	MakeEmpty();//메모리누수를 막기위해 노드의 데이터를 모두 제거한다

}
template<typename T>
void SortedLinkedList<T>::MakeEmpty()
{
	NodeType<T> *tempptr;
	while (m_pList != NULL)
	{
		tempptr = m_pList;
		m_pList = m_pList->next;
		delete tempptr;
	}	//리스트내의 모든 노드를 제거

	m_nLength = 0;		

}

template<typename T>
int SortedLinkedList<T>::Add(T &data)
{	//리스트의 첫 원소부터 시작
	ResetList();

	
	NodeType<T> *Node = new NodeType<T>;
	NodeType<T> *pre;
	bool Found = false;
	T dummy;


	Node->data = data;
	Node->next = NULL;
	if (IsEmpty())	//비어있을 경우
	{
		m_pList = Node;
		m_nLength++;	//성공적으로 추가했으므로 길이를 늘려준다
	}
	//list에 노드가 있을경우
	else
	{
		while (1)
		{	
			
			pre = m_pCurPointer;	//이전 노드를 가리키는 포인터 갱신, 첫 시작은 m_pList로 리스트의 첫부분이다

			
			GetNextItem(dummy);	//m_pCurPointer을 한칸 뒤로 민다.
			if (m_pCurPointer->data == Node->data)
				break;			//같은 데이터가 있을경우 추가하지 않고 반복문을 탈출한다..

			if (m_pCurPointer->data > Node->data)		//Node의 데이터가 현재 포인터의 값보다 작아질때까지 node가 들어갈 위치를 뒤로 민다.
			{
				if (pre == NULL) //리스트 맨 앞 장소에 넣어야 할때 첫번째 원소로 삽입한다
				{
					Node->next = m_pCurPointer;
					m_pList = Node;
					m_nLength++;	//성공적으로 추가했으므로 break 하기전에 길이를 늘려준다
					break;
				}
				Node->next = m_pCurPointer;
				pre->next = Node;
				m_nLength++;		//성공적으로 추가했으므로 break 하기전 길이를 늘려준다.
				break;


			}

			//Node 포인터가 마지막 노드를 가리키면 그 뒤에 Node를 삽입한다.
			if (m_pCurPointer->next == NULL)
			{
				m_pCurPointer->next = Node;
				m_nLength++;
				break;

			}
		}
	
		


	}


	return 1;
}

template<typename T>
int SortedLinkedList<T>::Delete(T& data)
{
	bool MoreToSearch, found;
	NodeType<T> *pre = NULL;

	m_pCurPointer = m_pList;
	found = false;
	MoreToSearch = (m_pCurPointer != NULL);	

	while(MoreToSearch && !found)
	{
		if (data == m_pCurPointer->data) //현재 가리키는 원소가 패러미터로 넣은 값과 같은가?
		{
			found = true;	//찾았으므로 found = true
			if (pre == NULL)	//찾은 항목이 첫번째 원소일경우
			{	
				delete m_pList;	//첫원소를 삭제한다.
				m_pList = m_pCurPointer->next; //찾은 항목이 첫 항목일경우 다음 원소를 첫번째 원소로 한다.
			}
			else
			{
				pre->next = m_pCurPointer->next;
				delete m_pCurPointer;
			}	



		}
		else
		{
			pre = m_pCurPointer;
			m_pCurPointer = m_pCurPointer->next;
			MoreToSearch = (m_pCurPointer != NULL);

		}	//못 찾을경우 m_CurPointer은 다음 원소를 가리킨다. 단 Pre는 현재원소를 가리킨다.	
	}

	if (found) //찾았을 경우
	{	m_nLength--;
		return 1;
		
	}
	else    //못 찾으면	
		return 0;



}

template<typename T>
int SortedLinkedList<T>::Replace(T& data)
{
	bool MoreToSearch, found;
	NodeType<T> *location;

	location = m_pList;
	found = false;
	MoreToSearch = (location != NULL);

	while (MoreToSearch && !found) //리스트의 끝이 아니면서 아직 몾찾을경우 반복한다
	{
		if (data == location->data) //일치하는 경우를 찾으면
		{
			found = true;
			location->data = data;
		}		//찾았으므로 found 는 true가되고 해당위치에 data값을 넣는다
		else
		{
			location = location->next;
			MoreToSearch = (location != NULL);	//리스트의 끝이 아닐경우 계속찾는다.

		}	//찾지 못했을 때 다음 location으로 옮긴다.

	}

	if (found) //찾았을 경우
	{	m_nLength--;
		return 1;
		
	}
	else
		return 0;		//못 찾음

}

template<typename T>
int SortedLinkedList<T>::Get(T& data)
{
	bool MoreToSearch, found;
	NodeType<T>* location;

	location = m_pList;
	found = false;
	MoreToSearch = (location != NULL);

	while(MoreToSearch&& !found)
	{
		if (data == location->data)		//일치하는 항목을 찾으면
		{
			found = true;
			data = location->data;
		}
		else
		{
		
			location = location->next;	//못찾으면 다음위치로 민다
			MoreToSearch = (location != NULL); //다음위치가 마지막이 아닐경우 계속 찾는다.
		}
	
	}
	if (found) //찾았으면
		return 1;
	else //못 찾았으면
	{
		return 0;
	}



}

template<typename T>
void SortedLinkedList<T>::ResetList()
{
	m_pCurPointer = NULL;

}

template<typename T>
void SortedLinkedList<T>::GetNextItem(T& data)
{
	if (m_pCurPointer == NULL)	//NULL이면
		m_pCurPointer = m_pList; //처음을 가리킨다
	else
		m_pCurPointer = m_pCurPointer->next;

	data = m_pCurPointer->data;

}


template<typename T>
void SortedLinkedList<T>::GetCuritem(T& item)
{
	// m_pCurPointer가 NULL이라면 처음 node를 가리킴.
	if (m_pCurPointer == NULL)
	{
		m_pCurPointer = m_pList;
	}

	item = m_pCurPointer->data;
	
}

template<typename T>
int SortedLinkedList<T>::GetFirstItem(T& item)
{
	if (m_nLength == 0)	// 리스트에 아무것도 없으면
		return	0;	// Get하지 못했으니 0 리턴
	else //리스트에 뭔가 있으면
	{
		item = m_pList->data;		//리스트의 첫지점의 값을 받고
		m_pCurPointer = m_pList->next;	//CurPointer를 다음으로 옮긴다.
		return 1;	// Get했으니 1리턴
	}



}

template<typename T>
SortedLinkedList<T>::SortedLinkedList(const SortedLinkedList<T>& anotherList)
{
	m_pList = NULL;
	m_pCurPointer = NULL;
	if (anotherList.m_pList == NULL)
		return;
	else {
		this->m_nLength = anotherList.m_nLength;

		NodeType<T> *Node1 = new NodeType<T>;
		NodeType<T> *Node2;
		m_pList = Node1;
		Node1->data = anotherList.m_pList->data;
		Node2 = anotherList.m_pList->next;
		
		while (Node2 != NULL)
		{
			Node1->next = new NodeType<T>;
			Node1 = Node1->next;
			Node1->data = Node2->data;
			Node2 = Node2->next;


		}
		Node1->next = NULL;

	}

	
}

template<typename T>
SortedLinkedList<T> SortedLinkedList<T>::operator=(const SortedLinkedList<T> &anotherList)
{
	MakeEmpty();
	//SortedLinkedList<T> temp(anotherList);
	
	m_pList = NULL;
	m_pCurPointer = NULL;
	
	if (anotherList.m_pList == NULL)
		return *this;
	else {
		this->m_nLength = anotherList.m_nLength;

		NodeType<T> *Node1 = new NodeType<T>;
		NodeType<T> *Node2;
		m_pList = Node1;
		Node1->data = anotherList.m_pList->data;
		Node2 = anotherList.m_pList->next;

		while (Node2 != NULL)
		{
			Node1->next = new NodeType<T>;
			Node1 = Node1->next;
			Node1->data = Node2->data;
			Node2 = Node2->next;


		}
		Node1->next = NULL;

	}
	
	//return temp;
	return *this;		//
}