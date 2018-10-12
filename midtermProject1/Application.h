#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
#include<sstream>
using namespace std;


#include "MusicType.h"
#include "SimplifiedType.h"
#include"SortedLinkedList.h"
#include"GenreType.h"
#include "CircularQueueType.h"
#include"AlbumType.h"
#include"ArtistType.h"
#define FILENameSIZE 1024

/**
*	application class for item management simply.
*/
class Application
{
public:
	/**
	*	default constructor.
	*/
	Application()
	{
		m_Command = 0;
		RemakeAlbumList = true;
		RemakeArtistList = true;
		RemakeGenreList = true;
	}

	/**
	*	destructor.
	*/
	~Application() {}

	/**
	*	@brief	Program driver.
	*	@pre	program is started.
	*	@post	program is finished.
	*/
	void Run();

	/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	user's command.
	*/
	int GetCommand();

	/**
	*	@brief	Add new record into list.
	*	@pre	list should be initialized.
	*	@post	new record is added into the list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddMusic();

	/**
	*	@brief	Display all records in the list on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllMusic();

	/**
	*	@brief	Open a file by file descriptor as an input file.
	*	@pre	a file for reading is exist.
	*	@post	open the file for reading.
	*	@param	fileName	a fileName to open for reading.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenInFile(char *fileName);

	/**
	*	@brief	Open a file by file descriptor as an output file.
	*	@pre	list should be initialized.
	*	@post	open the file for writing.
	*	@param	fileName	a fileName to open for writing.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenOutFile(char *fileName);

	/**
	*	@brief	Open a file as a read mode, read all data on the file, and set list by the data.
	*	@pre	The file is not opened.
	*	@post	list holds all records from the file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile();

	/**
	*	@brief	Open a file as a write mode, and write all data into the file,
	*	@pre	The file is not opened.
	*	@post	the list is stored in the output file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile();

	/**
*	@brief	객체를 생성 후, 문자열을 입력받는다.
*	@pre	없다.
*	@post	SearchByName함수에 문자열이 설정된 객체를 전달한다.
*	@return	없다.
*/
	void RetreiveRecordByName();

	/**
	*	@brief	inData의 이름 부분을 포함하는 문자열을 찾아 출력한다.
	*	@pre	inData의 이름 부분이 초기화되어있어야 한다.
	*	@post	inData에 알맞은 항목이 복사된다.
	*	@param	inData	이름이 설정되어있고 나머지는 비어있는 Musictype
	*	@return	없다.
	*/
	void SearchByName(MusicType &inData);

	/**
*	@brief	객체를 생성 후, 문자열을 입력받는다.
*	@pre	없다.
*	@post	SearchBySinger함수에 문자열이 설정된 객체를 전달한다.
*	@return	없다.
*/
	void RetreiveRecordBySinger();

	/**
	*	@brief	inData의 이름 부분을 포함하는 문자열을 찾아 출력한다.
	*	@pre	inData의 이름 부분이 초기화되어있어야 한다.
	*	@post	inData에 알맞은 항목이 복사된다.
	*	@param	inData	이름이 설정되어있고 나머지는 비어있는 Musictype
	*	@return	없다.
	*/
	void SearchBySinger(MusicType &inData);


	/**
*	@brief	객체를 생성 후, 문자열을 입력받는다.
*	@pre	없다.
*	@post	SearchByAlbum함수에 문자열이 설정된 객체를 전달한다.
*	@return	없다.
*/
	void RetreiveRecordByAlbum();

	/**
	*	@brief	inData의 이름 부분을 포함하는 문자열을 찾아 출력한다.
	*	@pre	inData의 이름 부분이 초기화되어있어야 한다.
	*	@post	inData에 알맞은 항목이 복사된다.
	*	@param	inData	이름이 설정되어있고 나머지는 비어있는 Musictype
	*	@return	없다.
	*/
	void SearchByAlbum(MusicType &inData);
	/**
*	@brief	객체를 생성 후, 문자열을 입력받는다.
*	@pre	없다.
*	@post	SearchByGenre함수에 문자열이 설정된 객체를 전달한다.
*	@return	없다.
*/
	void RetreiveRecordByGenre();

	/**
	*	@brief	inData의 이름 부분을 포함하는 문자열을 찾아 출력한다.
	*	@pre	inData의 이름 부분이 초기화되어있어야 한다.
	*	@post	inData에 알맞은 항목이 복사된다.
	*	@param	inData	이름이 설정되어있고 나머지는 비어있는 Musictype
	*	@return	없다.
	*/
	void SearchByGenre(MusicType &inData);
	/**
	*	@brief	inData의 Index와 같은 Index를 가진 MusicList의 정보를 찾아온다
	*	@pre	inData의 Index가 초기화 되어 있어야 한다.
	*	@post	inData에 알맞은 항목이 복사된다.
	*	@param	inData	Index가 설정되어있고 나머지는 비어있는 Musictype
	*	@return	없다.
	*/
	
	void SearchByIndex(MusicType &indata);
	/**
	*	@brief	사용자에게 Name을 입력받아 SortedList의 Delete함수에 넘겨주는 역할을 한다.
	*	@pre	없다.
	*	@post	사용자가 입력한 Name을 가지고 있는 Musictype이 m_List에서 사라진다.
	*	@return	없다.
	*/
	
	void Delete();

	/**
	*	@brief	사용자에게 Name을 입력받아 SortedList의 Replace함수에 넘겨주는 역할을 한다.
	*	@pre	없다.
	*	@post	사용자가 입력한 Name을 가지고 있는 MusicType을 다시 입력받아 갱신한다.
	*	@return	없다.
	*/
	void Update();
	/**
	*	@brief	최근에 추가된 30곡의 자세한 정보를 화면에 출력
	*	@pre	없다.
	*	@post	없다.
	*	@return	없다.
	*/
	void DIsplayNewMusic();
	/**
	*	@brief	Primary key를 이용해 원하는 음악정보가져온다.
	*	@pre	리스트가 초기화되어야함.
	*	@post	inData에 원하는 곡정보가 담김
	*	@return	찾으면 1, 아니면 0
	*	@param key 곡번호를 찾기위한 int형 변수
	*	@inData 원하는 곡의 정보를 받아오기 위한 변수
	*/
	bool Search(int key, MusicType& inData);
	/**
	*	@brief	장르 리스트에 있는 곡들을 장르에 맞춰 출력
	*	@pre	없다.
	*	@post	없다.
	*	@return	없다.
	*/
	void DisplayMusicbyGenre();

	/**
*	@brief	객체를 생성 후, 문자열을 입력받는다.
*	@pre	없다.
*	@post	SearchByNameNGenre함수에 문자열이 설정된 객체를 전달한다.
*	@return	없다.
*/
	void RetreiveRecordByNameNGenre();

	/**
	*	@brief	inData의 이름 부분을 포함하는 문자열을 찾아 출력한다.
	*	@pre	inData의 이름 부분이 초기화되어있어야 한다.
	*	@post	inData에 알맞은 항목이 복사된다.
	*	@param	inData	이름이 설정되어있고 나머지는 비어있는 Musictype
	*	@return	없다.
	*/
	void SearchByNameNGenre(MusicType &inData);
	/**
*	@brief	MusicList에 있는 곡을 앨범별로 출력한다.
*	@pre	없다.
*	@post	없다.
*	@return	없다.
*/
	void DisplayMusicByAlbum();
	/**
*	@brief	MusicList에 있는 곡을 아티스트별로 나누고, 각 아티스트별 로 앨범을 분류하여 출력한다.
*	@pre	없다.
*	@post	없다.
*	@return	없다.
*/
	void DisplayMusicByArtist();
	/**
*	@brief	MusicList에 있는 곡을 Primary Key에 따라 정렬된 순서에 따라 Index를 부여한다
*	@pre	MusicList에 최소한 하나이상의 곡이 있어야한다.
*	@post	MusicList의 각 MusicType에 Index가 부여된다
*	@return	없다.
*/
	void SetMusicIndex();
	/**
*	@brief	MusicList의 Music을 분류하는 하위리스트들을 다시 만들기 위한 조건을 충족시킨다.
*	@pre	곡이 추가되거나, 삭제되거나, 변경되어야 한다.
*	@post	Remake~~List 형의 변수의 값이 모두 true가 된다.
*	@return	없다.
*/
	void RemakeSubList()
	{
		RemakeAlbumList = true;
		RemakeArtistList = true;
		RemakeGenreList = true;
	};

	
private:
	ifstream m_InFile;		///< input file descriptor.
	ofstream m_OutFile;		///< output file descriptor.
	SortedLinkedList<MusicType> m_List;		/// 노래 리스트
	CircularQueueType<SimplifiedType> AddRecentlyMusicList;			//최근음악리스트
	CircularQueueType<MusicType*> AddRList;
	int m_Command;			///< current command number.
	SortedLinkedList<AlbumType> AlbumList;			//앨범을 분류하기 위한 앨범리스트
	SortedLinkedList<ArtistType> ArtistList;		//아티스트를 분류하기 위한 아티스트리스트
	SortedLinkedList <string> GenreList;		//장르를 분류하기 위한 장르 리스트
	//아래의 변수들은 각 하위 리스트를 다시만들어야 할지 판별하는 변수이다.
	bool RemakeAlbumList;			
	bool RemakeArtistList;
	bool RemakeGenreList;

};


// Program driver.
void Application::Run()
{
	while (1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:		// read a record and add to list.
			AddMusic();
			break;
		case 2:		// display all the records in list on screen.
			Delete();
			break;
		case 3:
			Update();
			break;
		case 4:	//곡명으로 검색
			RetreiveRecordByName();
			break;
		case 5:	//가수명으로 검색
			RetreiveRecordBySinger();
			break;
		case 6:	//앨범명으로 검색
			RetreiveRecordByAlbum();
			break;
		case 7:	//장르로 검색
			RetreiveRecordByGenre();
			break;
		case 8:		// load list data from a file.
			DisplayAllMusic();
			break;
	//	case 9:
		//	DIsplayNewMusic();
			//break;
		case 10:
			DisplayMusicbyGenre();
			break;
		case 11:
			RetreiveRecordByNameNGenre();
			break;
		case 12:
			DisplayMusicByAlbum();
			break;
		case 13:
			DisplayMusicByArtist();
			break;
		case 98:
			ReadDataFromFile();
			break;
		case 99:
			WriteDataToFile();
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}


// Display command on screen and get a input from keyboard.
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add Music" << endl;
	cout << "\t   2 : Delete Music" << endl;
	cout << "\t   3 : Replace Music" << endl;
	cout << "\t   4 : Search by Song Name" << endl;
	cout << "\t   5 : Search by Artist(Singer)" << endl;
	cout << "\t   6 : Search by Album" << endl;
	cout << "\t   7 : Search by Genre" << endl;
	cout << "\t   8 : Display all Music" << endl;
//	cout << "\t   9 : Display New Music" << endl;
	cout << "\t   10 : Display Music by Genre" << endl;
	cout << "\t   11 : search by Name and Genre" << endl;
	cout << "\t   12 : Display Music by Album" << endl;
	cout << "\t   13 : Display Music by Artist" << endl;
	cout << "\t   98 : Get from file" << endl;
	cout << "\t   99 : Put to file " << endl;
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


// Add new record into list.
int Application::AddMusic()
{
	string genre;	//장르를 저장할 임시변수
	string name;	//곡명을 저장할 임시변수
	MusicType item;
	SimplifiedType Simpletype;	//곡번호, 곡명만 저장할 타입
	item.SetInfoFromKB();
	m_List.Add(item);		//MusicList에 원소 추가
	RemakeSubList();		//MusicList에 변화가 생겼으므로 하위 리스트들을 다시 만들어줘야 한다.
	SetMusicIndex();		//MusicList에 변화가 생겼으므로 Index를 다시 부여한다.
	

	//최근 추가목록에 추가하기
	/*

	

	Simpletype.SetRecord(num, name);		
	if (!AddRecentlyMusicList.IsFull())		//최근 추가된목록이 가득차지 않았을경우	
		AddRecentlyMusicList.EnQueue(Simpletype);			//큐에 하나 추가
	else									//최근 추가된목록이 30개 꽉 찼을경우
	{
		SimplifiedType S_temp;
		AddRecentlyMusicList.DeQueue(S_temp);		//하나를 지우고
		AddRecentlyMusicList.EnQueue(Simpletype);	//방금 추가된 레코드를 집어넣는다
	}
	*/
	// 현재 list 출력
	DisplayAllMusic();

	return 1;
}


// Display all records in the list on screen.
void Application::DisplayAllMusic()
{
	MusicType data;
	if (m_List.GetLength() == 0)
		return;
	cout << "\n\tCurrent list" << endl;

	// list의 모든 데이터를 화면에 출력
	m_List.ResetList();
	do {
		m_List.GetCuritem(data);
		m_List.GotoNextItem();
		data.DisplayRecordOnScreen();

	} while (!m_List.IsLastPointer_NotResetList());

}



//찾을 ID를 사용자에게 입력받고 SortedList의 Delete함수를 호출한다.
void Application::Delete()
{
	cout << "\t지울 : ";
	MusicType data;	//Delete함수는 MusicType을 파라미터로 갖기 때문에 임의로 만들어준다.
	data.SetNumFromKB();	//사용자에게서 곡 번호를 입력받는다.
	SearchByIndex(data);

	if (m_List.Delete(data))	//Delete함수에 data를 넘겨준다.
	{
		cout << "\t삭제를 완료했습니다." << endl;	//삭제에 성공했으면 메시지를 출력한다.
		RemakeSubList();		//MusicList에 변화가 생겼으므로 하위 리스트들을 다시 만들어줘야 한다.
		if (m_List.GetLength() != 0)		//길이가 0이면 인덱스를 부여할수 없다.
		{
			SetMusicIndex();//MusicList에 변화가 생겼으므로 Index를 다시 부여한다.
		}
	}
	else
		cout << "\t삭제하지 못했습니다. 일치하는 항목을 찾을 수 없습니다." << endl;	//삭제에 실패했으면 메시지를 출력한다.

	
}


//찾을 ID를 사용자에게 입력받고 SortedList의 Update함수를 호출한다.
void Application::Update()
{
	cout << "\t변경을 원하는 항목의 ";
	MusicType data;	//Replace함수는 MusicType을 파라미터로 갖기 때문에 임의로 만들어준다.
	data.SetNumFromKB();	//사용자에게서 수정할 항목의 곡 번호를 입력받는다.
	SearchByIndex(data);
	if (!m_List.Get(data))	//사용자가 입력한 항목이 List에 있나 검색
	{
		cout << "\t항목을 찾을 수 없습니다." << endl;		//찾을 수 없을때 메시지를 출력한다.
		return;
	}
	else	//찾을 수 있을때
	{	
		data.SetNameFromKB(); //사용자에게서 곡명을 입력받는다.
		data.SetSingerFromKB();	//사용자에게서 가수를 입력받는다.
		data.SetAlbumFromKB();	//사용자에게서 앨범을 입력받는다.
		data.SetGenreFromKB();  //사용자에게서 장르를 입력받는다.
		data.SetLyricsFromKB(); // 사용자에게서 가사를 입력받는다.
		if (m_List.Delete(data))//기존 항목을 삭제하고
		{	
			data.SetPkey();	//데이터를 변경했으므로 Pkey를 다시 지정해준다.
			m_List.Add(data);
			cout << "\t수정을 완료했습니다." << endl;	//수정을 성공했을 때 메시지를 출력한다.
			RemakeSubList();		//MusicList에 변화가 생겼으므로 하위 리스트들을 다시 만들어줘야 한다.
			if (m_List.GetLength() != 0)		//길이가 0이면 인덱스를 부여할수 없다.
			{
				SetMusicIndex();//MusicList에 변화가 생겼으므로 Index를 다시 부여한다.
			}
		}
		else
			cout << "\t수정을 실패했습니다." << endl;	//수정에 실패했을 때 메시지를 출력한다.
	}
	
}
//사용자에게 찾고자하는 Name을 입력받고 넘겨주는 역할을 한다.
void Application::RetreiveRecordByName()
{
	MusicType temp;
	cout << "\t찾을 ";
	temp.SetNameFromKB();	//SearchByName함수에 넘겨줄 temp의 Name을 사용자에게 입력받는다.
	SearchByName(temp);	//실질적으로 찾는 동작을 하는 SearchByName함수를 호출하고 temp값을 넘겨준다.
}


//사용자가 찾고자하는 Name을 포함하는 inData로 m_List의 항목들 중 일치하는 항목을 찾고 출력해준다. **프로그램에 전반적으로 Array에 index를 직접 접근하는 방법을 선호했으나 이 함수는 Application 클래스의 메소드이므로 GetNextItem함수를 이용해 iteration을 이용했습니다.
void Application::SearchByName(MusicType &inData)
{
	if (m_List.IsEmpty() == true)
	{
		cout << "리스트에 아무것도 없습니다." << endl;
		return;
	}
	MusicType temp;	//m_List의 값을 비교해주기 위한 임시 MusicType.
	m_List.ResetList();
	int count = 0;
	m_List.GetCuritem(temp);
	m_List.GotoNextItem();
	if (temp.GetName().find(inData.GetName()) != -1 && temp.GetName().find(inData.GetName()) != -1)
	{
		temp.DisplayRecordOnScreen();
		count++;
	}	//첫번쨰 아이템이 일치하는지 확인한다
	while (!m_List.IsLastPointer_NotResetList())	//첫번째 아이템을 받아온 이후론 반복을 통해 리스트 끝까지 확인한다.
	{
		m_List.GetCuritem(temp);
		if (temp.GetName().find(inData.GetName()) != -1 && temp.GetName().find(inData.GetName()) != -1)
		{
			temp.DisplayRecordOnScreen();
			count++;
		}
		m_List.GotoNextItem();
	}
	if (count == 0)
		cout << "\t찾을 수 없습니다." << endl;	//찾은 개수가 0개이면 찾을 수 없다는 메시지를 출력한다.
}

//사용자에게 찾고자하는 Singer을 입력받고 넘겨주는 역할을 한다.
void Application::RetreiveRecordBySinger()
{
	MusicType temp;
	cout << "\t찾을 ";
	temp.SetSingerFromKB();	//SearchBySinger함수에 넘겨줄 temp의 Name을 사용자에게 입력받는다.
	SearchBySinger(temp);	//실질적으로 찾는 동작을 하는 SearchBySinger함수를 호출하고 temp값을 넘겨준다.
}


//사용자가 찾고자하는 Singer을 포함하는 inData로 m_List의 항목들 중 일치하는 항목을 찾고 출력해준다. **프로그램에 전반적으로 Array에 index를 직접 접근하는 방법을 선호했으나 이 함수는 Application 클래스의 메소드이므로 GetNextItem함수를 이용해 iteration을 이용했습니다.
void Application::SearchBySinger(MusicType &inData)
{	
	if (m_List.IsEmpty() == true)
	{
		cout << "리스트에 아무것도 없습니다." << endl;
		return;
	}
	MusicType temp;	//m_List의 값을 비교해주기 위한 임시 MusicType.
	m_List.ResetList();
	int count = 0;
	m_List.GetCuritem(temp);
	m_List.GotoNextItem();
	if (temp.GetSinger().find(inData.GetSinger()) != -1 && temp.GetSinger().find(inData.GetSinger()) != -1)
	{
		temp.DisplayRecordOnScreen();
		count++;
	}	//첫번쨰 아이템이 일치하는지 확인한다
	while (!m_List.IsLastPointer_NotResetList())	//첫번째 아이템을 받아온 이후론 반복을 통해 리스트 끝까지 확인한다.
	{
		m_List.GetCuritem(temp);
		if (temp.GetSinger().find(inData.GetSinger()) != -1 && temp.GetSinger().find(inData.GetSinger()) != -1)
		{
			temp.DisplayRecordOnScreen();
			count++;
		}
		m_List.GotoNextItem();
	}
	if (count == 0)
		cout << "\t찾을 수 없습니다." << endl;	//찾은 개수가 0개이면 찾을 수 없다는 메시지를 출력한다.
}

//사용자에게 찾고자하는 Album을 입력받고 넘겨주는 역할을 한다.
void Application::RetreiveRecordByAlbum()
{
	MusicType temp;
	cout << "\t찾을 ";
	temp.SetAlbumFromKB();	//SearchByAlbum함수에 넘겨줄 temp의 Album을 사용자에게 입력받는다.
	SearchByAlbum(temp);	//실질적으로 찾는 동작을 하는 SearchByAlbum함수를 호출하고 temp값을 넘겨준다.
}


//사용자가 찾고자하는 Album을 포함하는 inData로 m_List의 항목들 중 일치하는 항목을 찾고 출력해준다. **프로그램에 전반적으로 Array에 index를 직접 접근하는 방법을 선호했으나 이 함수는 Application 클래스의 메소드이므로 GetNextItem함수를 이용해 iteration을 이용했습니다.
void Application::SearchByAlbum(MusicType &inData)
{
	if (m_List.IsEmpty() == true)
	{
		cout << "리스트에 아무것도 없습니다." << endl;
		return;
	}
	MusicType temp;	//m_List의 값을 비교해주기 위한 임시 MusicType.
	m_List.ResetList();
	int count = 0;
	m_List.GetCuritem(temp);
	m_List.GotoNextItem();
	if (temp.GetAlbum().find(inData.GetAlbum()) != -1 && temp.GetAlbum().find(inData.GetAlbum()) != -1)
	{
		temp.DisplayRecordOnScreen();
		count++;
	}	//첫번쨰 아이템이 일치하는지 확인한다
	while (!m_List.IsLastPointer_NotResetList())	//첫번째 아이템을 받아온 이후론 반복을 통해 리스트 끝까지 확인한다.
	{
		m_List.GetCuritem(temp);
		if (temp.GetAlbum().find(inData.GetAlbum()) != -1 && temp.GetAlbum().find(inData.GetAlbum()) != -1)
		{
			temp.DisplayRecordOnScreen();
			count++;
		}
		m_List.GotoNextItem();
	}
	if (count == 0)
		cout << "\t찾을 수 없습니다." << endl;	//찾은 개수가 0개이면 찾을 수 없다는 메시지를 출력한다.
}
//사용자에게 찾고자하는 Genre을 입력받고 넘겨주는 역할을 한다.
void Application::RetreiveRecordByGenre()
{
	MusicType temp;
	cout << "\t찾을 ";
	temp.SetGenreFromKB();	//SearchByGenre함수에 넘겨줄 temp의 Genre을 사용자에게 입력받는다.
	SearchByGenre(temp);	//실질적으로 찾는 동작을 하는 SearchByGenre함수를 호출하고 temp값을 넘겨준다.
}


//사용자가 찾고자하는 Genre을 포함하는 inData로 m_List의 항목들 중 일치하는 항목을 찾고 출력해준다. **프로그램에 전반적으로 Array에 index를 직접 접근하는 방법을 선호했으나 이 함수는 Application 클래스의 메소드이므로 GetNextItem함수를 이용해 iteration을 이용했습니다.
void Application::SearchByGenre(MusicType &inData)
{
	if (m_List.IsEmpty() == true)
	{
		cout << "리스트에 아무것도 없습니다." << endl;
		return;
	}
	MusicType temp;	//m_List의 값을 비교해주기 위한 임시 MusicType.
	m_List.ResetList();
	int count = 0;
	m_List.GetCuritem(temp);
	m_List.GotoNextItem();
	if (temp.GetGenre().find(inData.GetGenre()) != -1 && temp.GetGenre().find(inData.GetGenre()) != -1)
	{
		temp.DisplayRecordOnScreen();
		count++;
	}	//첫번쨰 아이템이 일치하는지 확인한다
	while (!m_List.IsLastPointer_NotResetList())	//첫번째 아이템을 받아온 이후론 반복을 통해 리스트 끝까지 확인한다.
	{
		m_List.GetCuritem(temp);
		if (temp.GetGenre().find(inData.GetGenre()) != -1 && temp.GetGenre().find(inData.GetGenre()) != -1)
		{
			temp.DisplayRecordOnScreen();
			count++;
		}
		m_List.GotoNextItem();
	}
	if (count == 0)
		cout << "\t찾을 수 없습니다." << endl;	//찾은 개수가 0개이면 찾을 수 없다는 메시지를 출력한다.
}

// Open a file by file descriptor as an input file.
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);	// file open for reading.

	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_InFile)	return 0;
	else	return 1;
}


// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_OutFile)	return 0;
	else	return 1;
}


// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile()
{
	int index = 0;
	MusicType data;	// 읽기용 임시 변수
	ifstream ReadData;
	ReadData.open("text.txt");
	string OneLine;
	while (getline(ReadData, OneLine))
	{
		istringstream L(OneLine);
		string name, singer, Album, Genre, Lyrics;
		L >> name;
		L >> singer;
		L >> Album;
		L >> Genre;
		L >> Lyrics;
		data.SetRecord(name, singer, Album, Genre, Lyrics);
		m_List.Add(data);
	}
	/*
	char fileName[FILENameSIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> fileName;

	// file open, open error가 발생하면 0을 리턴
	if (!OpenInFile(fileName))
		return 0;

	// 파일의 모든 내용을 읽어 list에 추가
	while (!m_InFile.eof())
	{
		// array에 학생들의 정보가 들어있는 structure 저장
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);
	}

	m_InFile.close();	// file close
	*/
	SetMusicIndex();
	// 현재 list 출력
	DisplayAllMusic();

	return 1;
}


// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile()
{
	MusicType data;	// 쓰기용 임시 변수

	char fileName[FILENameSIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> fileName;

	// file open, open error가 발생하면 0을 리턴
	if (!OpenOutFile(fileName))
		return 0;

	// list 포인터를 초기화
	m_List.ResetList();

	// list의 모든 데이터를 파일에 쓰기

	m_List.GetCuritem(data);
	data.WriteDataToFile(m_OutFile);
	m_List.GotoNextItem();

	while (!m_List.IsLastPointer_NotResetList())
	{
		m_List.GetCuritem(data);
		data.WriteDataToFile(m_OutFile);
		m_List.GotoNextItem();

	}

	m_OutFile.close();	// file close

	return 1;
}

//최근 추가된 30곡 출력
void Application::DIsplayNewMusic()
{
	if (m_List.IsEmpty() == true)
	{
		cout << "리스트에 아무것도 없습니다." << endl;
		return;
	}
	int key;
	SimplifiedType S_temp;
	MusicType M_temp;
	AddRecentlyMusicList.ResetQueue();
	AddRecentlyMusicList.GetCurrentitem(S_temp);		//index == rear 인 상태의 레코드를 받아온다.
	key = S_temp.getSongNum();
	Search(key, M_temp);
	M_temp.DisplayRecordOnScreen();
	while (AddRecentlyMusicList.GetNextitem(S_temp) != -1)
	{
		key = S_temp.getSongNum();
		Search(key, M_temp);
		M_temp.DisplayRecordOnScreen();


	}
}

bool Application::Search(int key, MusicType& inData)
{
	inData.SetNum(key);
	if (m_List.Get(inData))
		return true;

	else
		return false;
}
//Display Music by genre through genre list
void Application::DisplayMusicbyGenre()
{	
	if (m_List.GetLength() == 0)
		return;
	if (RemakeGenreList == true)
	{
		GenreList.MakeEmpty();		//기존의 리스트를 지운다.
		m_List.ResetList();
		MusicType temp;

		do {
			string thisGenre;
			m_List.GetCuritem(temp);
			thisGenre = temp.GetGenre();
			GenreList.Add(thisGenre);
			m_List.GotoNextItem();
		} while (!m_List.IsLastPointer_NotResetList());	//여기까지 왔으면 장르별로 추가완료 된다.
	}
		RemakeGenreList = false;			//변경이 없으면 리스트를 다시 만들필요가 없다.

		//아래는 출력하는 코드
		GenreList.ResetList();
		do {
			string thisGenre;
			GenreList.GetCuritem(thisGenre);
			cout << "\t 장르 : " << thisGenre << endl;
			cout << "\t ------------- " << endl;
			m_List.ResetList();
			do {
				MusicType temp2;
				m_List.GetCuritem(temp2);
				if (temp2.GetGenre() == thisGenre)
				{
					temp2.DisplayRecordOnScreen();

				}
				m_List.GotoNextItem();
			} while (!m_List.IsLastPointer_NotResetList());
			cout << "\t ------------- " << endl;
			GenreList.GotoNextItem();
		} while (!GenreList.IsLastPointer_NotResetList());

	

}



//name 과 genre 정보를 받아 Search함수에 넘긴다.
void Application::RetreiveRecordByNameNGenre()
{
	MusicType temp;
	cout << "\t찾을 ";
	temp.SetNameFromKB();
	temp.SetGenreFromKB();	//SearchByGenre함수에 넘겨줄 temp의 Genre을 사용자에게 입력받는다.
	SearchByNameNGenre(temp);	//실질적으로 찾는 동작을 하는 SearchByGenre함수를 호출하고 temp값을 넘겨준다.


}

void Application::SearchByNameNGenre(MusicType& inData)
{
	if (m_List.IsEmpty() == true)
	{
		cout << "리스트에 아무것도 없습니다." << endl;
		return;
	}
	MusicType temp;	//m_List의 값을 비교해주기 위한 임시 MusicType.
	m_List.ResetList();
	int count = 0;
	m_List.GetCuritem(temp);
	m_List.GotoNextItem();
	if (temp.GetGenre().find(inData.GetGenre()) != -1 && temp.GetName().find(inData.GetName()) != -1)	//find함수에서는 일치하는 항목이 존재하지 않을때 -1을 리턴하므로 -1이 아니면 일치하는 문자열이 있는것이다.
	{
		temp.DisplayRecordOnScreen();
		count++;
	}	//첫번쨰 아이템이 일치하는지 확인한다
	while (!m_List.IsLastPointer_NotResetList())	//첫번째 아이템을 받아온 이후론 반복을 통해 리스트 끝까지 확인한다.
	{
		m_List.GetCuritem(temp);
		if (temp.GetGenre().find(inData.GetGenre()) != -1 && temp.GetName().find(inData.GetName()) != -1)	//find함수에서는 일치하는 항목이 존재하지 않을때 -1을 리턴하므로 -1이 아니면 일치하는 문자열이 있는것이다.
		{
			temp.DisplayRecordOnScreen();	//일치하는 문자열을 포함하는 temp의 내용을 출력한다.
			count++;	//찾은 개수를 1 늘려준다.
		}
		m_List.GotoNextItem();
	}
	if (count == 0)
		cout << "\t찾을 수 없습니다." << endl;	//찾은 개수가 0개이면 찾을 수 없다는 메시지를 출력한다.



}

void Application::DisplayMusicByAlbum()
{
	
	if (m_List.GetLength() == 0)
		return;
	//쉽게 구현하기
	if (RemakeAlbumList == true)		//앨범 리스트를 다시만들어야 하는가
	{	
		AlbumList.MakeEmpty();		//기존의 앨범리스트를 비워준다.
		m_List.ResetList();
		do		//앨범별로 분류하기 위한 반복문 시작
		{
			MusicType tempmusic;
			m_List.GetCuritem(tempmusic);
			AlbumType Album;
			Album.SetAlbumName(tempmusic.GetAlbum());
			Album.SetArtistName(tempmusic.GetSinger());
			AlbumList.Add(Album);
			m_List.GotoNextItem();
		} while (!m_List.IsLastPointer_NotResetList());		//AlbumList에 앨범추가됨
		
		
	}
	RemakeAlbumList = false;		//리스트를 갱신했으므로 다시만들 필요가 없다.
	//여기서부터는 출력코드
	AlbumList.ResetList();
	do {


		AlbumType tempAlbum;
		AlbumList.GetCuritem(tempAlbum);
		cout << "\t앨범명 : " << tempAlbum.GetAlbumName() << "(아티스트: " << tempAlbum.GetArtistName() << ")" << endl;
		cout << "\t----------------------- " << endl;
		m_List.ResetList();
		do {
			MusicType tempMusic;
			m_List.GetCuritem(tempMusic);
			AlbumType tempAlbum2(tempMusic.GetAlbum(),tempMusic.GetSinger());
			if (tempAlbum == tempAlbum2)
			{
				tempMusic.DisplayNameOnScreen();
			}
			m_List.GotoNextItem();
		} while (!m_List.IsLastPointer_NotResetList());
		cout << "\t----------------------- " << endl;
		AlbumList.GotoNextItem();
	} while (!AlbumList.IsLastPointer_NotResetList());
	

}

void Application::DisplayMusicByArtist()
{
	if (m_List.GetLength() == 0)
		return;
	if (RemakeArtistList == true)		//아티스트 리스트를 다시 만들어야 하는가
	{
		ArtistList.MakeEmpty();		
		AlbumList.MakeEmpty();		//아티스트 리스트와 앨범리스트를 비운다
		m_List.ResetList();
		do {
			MusicType tempmusic;
			m_List.GetCuritem(tempmusic);
			ArtistType tempArtist;
			tempArtist.SetArtistName(tempmusic.GetSinger());
			ArtistList.Add(tempArtist);
			m_List.GotoNextItem();
		} while (!m_List.IsLastPointer_NotResetList());			//아티스트리스트에 아티스트가 정렬되어 삽입된다.	



		m_List.ResetList();
		do {
			MusicType tempmusic;
			m_List.GetCuritem(tempmusic);
			AlbumType Album;
			Album.SetAlbumName(tempmusic.GetAlbum());
			Album.SetArtistName(tempmusic.GetSinger());
			AlbumList.Add(Album);
			m_List.GotoNextItem();
		} while (!m_List.IsLastPointer_NotResetList());		//AlbumList에 앨범추가됨

		AlbumList.ResetList();				//앨범을 해당 앨범과 같은 아티스트를 가진 아티스트 타입의 리스트에 추가한다.
		do {
			AlbumType Album;
			AlbumList.GetCuritem(Album);
			ArtistList.ResetList();
			do {
				ArtistType tempArtist;
				ArtistType *tempArtist2;
				ArtistList.GetCuritem(tempArtist);
				if (Album.GetArtistName() == tempArtist.GetArtistName())	//같은거 현재 앨범타입의 아티스트와 같은 아티스트를 찾았으면
				{	
					tempArtist2 = ArtistList.GetCurItemAddress();
					tempArtist2->AddListinList(Album);		//포인터를 통해 리스트인리스트에 접근하여 추가한다.
					
				}
				ArtistList.GotoNextItem();
			} while (!ArtistList.IsLastPointer_NotResetList());




			AlbumList.GotoNextItem();
		} while (!AlbumList.IsLastPointer_NotResetList());

		
	}
	RemakeArtistList = false;	//리스트를 갱신했으므로 다시만들 필요가 없다.
	//여기서부턴 출력코드
	ArtistList.ResetList();
	do {
			ArtistType tempArtist;
			ArtistList.GetCuritem(tempArtist);
			cout << "\t아티스트 : " << tempArtist.GetArtistName() << endl;
			cout << "\t----------------------- " << endl;
			tempArtist.PrintListinList();
			cout << "\t----------------------- " << endl;
			ArtistList.GotoNextItem();

	} while (!ArtistList.IsLastPointer_NotResetList());


	
}
void Application::SetMusicIndex()
{	
	int Index = 1;
	m_List.ResetList();
	MusicType temp;
	MusicType *temp2;
	do {
		temp2 = m_List.GetCurItemAddress();
		temp2->SetNum(Index);
		Index++;
		m_List.GotoNextItem();
	} while (!m_List.IsLastPointer_NotResetList());		//List의 끝까지 인덱스를 부여한다. 인덱스의 최대값은 MusicList의 길이이다.



}
void Application::SearchByIndex(MusicType &indata)
{
	m_List.ResetList();

	do {
		MusicType temp;
		m_List.GetCuritem(temp);
		if (temp.GetNum() == indata.GetNum())
			indata = temp;
		m_List.GotoNextItem();

	} while (!m_List.IsLastPointer_NotResetList());


}



#endif	// _APPLICATION_H


