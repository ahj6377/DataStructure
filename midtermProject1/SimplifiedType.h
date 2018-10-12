#pragma once
#include<string>
#include<iostream>

using namespace std;
#include"MusicType.h"
/**
*	@brief	과제 1에서 이 클래스는 쓰이지 않는다.

*/
class SimplifiedType	//현재 이 타입은 사용하지 않는다.
{
public:
	SimplifiedType() {
		S_Name = "";
		S_Number = -1;
	}//기본 생성자
	~SimplifiedType() {}	//기본 소멸자				여기서 터짐

	SimplifiedType(int num, string name)
	{
		S_Number = num;
		S_Name = name;
	}
	/**
*	@brief	Set song number
*	@pre	X
*	@return	X
*/
	void setSongNum(int num)
	{
		S_Number = num;
	}
	/**
*	@brief	Set song Name
*	@pre	x
*	@post	song name is set
*/
	void setSongName(string name)
	{
		S_Name = name;
	}
	/**
*	@brief	Get song Number
*	@pre	song Number is set.
*	@post	none.
*	@return	song Number;
*/
	int getSongNum()
	{
		return S_Number;
	}
	/**
*	@brief	Get song Name
*	@pre	song Name is set.
*	@post	none.
*	@return	song Name;
*/
	string getSongName()
	{
		return S_Name;
	}
	/**
*	@brief	Set song Record
*	@pre	x
*	@post	song record is set
*/
	void SetRecord(int num, string name)
	{
		setSongNum(num);
		setSongName(name);
	}
	/**
*	@brief	Display simplifiedtype Record
*	@pre	song Record is set
*	@post	x
*	@return	x
*/
	void DisplayRecordOnScreen()
	{
		cout << "\t곡 번호 : " << S_Number << endl;
		cout << "\t곡 이름 : " << S_Name << endl;

	}
	/**
*	@brief	두 SimplifiedType의 Primary key가 같은지 비교함
*	@pre	비교하고자 하는 SimplifiedType이 초기화 되어있어야함
*	@post	x
*	@param	data 비교하고자 하는 데이터
*	@return	같을경우 true, 다를경우 false
*/
	bool operator==(SimplifiedType data)
	{

		if (this->getSongNum() == data.getSongNum())
			return true;
		else
			return false;
	}
	/**
*	@brief	두 SimplifiedType의 Primary key의 크기를 비교함
*	@pre	비교하고자 하는 SimplifiedType이 초기화 되어있어야함
*	@post	x
*	@param	data 비교하고자 하는 데이터
*	@return	좌변이 클경우 true 작을경우 false

*/
	bool operator>(SimplifiedType data)
	{
		if (this->getSongNum() > data.getSongNum())
			return true;
		else
			return false;
	}
	/**
*	@brief	두 SimplifiedType의 Primary key의 크기를 비교함
*	@pre	비교하고자 하는 SimplifiedType이 초기화 되어있어야함
*	@post	x
*	@param	data 비교하고자 하는 데이터
*	@return	우변이 클경우 true 작을경우 false
*/
	bool operator<(SimplifiedType data)
	{
		if (this->getSongNum() < data.getSongNum())
			return true;
		else
			return false;

	}
	SimplifiedType operator=(const SimplifiedType &data);
private:
	int S_Number;		//곡 번호
	string S_Name;		//곡명
//	MusicType* Mptr;	//곡을 관리하기 위한 포인터

};

SimplifiedType SimplifiedType::operator=(const SimplifiedType& data)
{
	S_Number = data.S_Number;
	S_Name = data.S_Name;




	return *this;

}