#pragma once
#include<string>
#include<iostream>

using namespace std;
#include"MusicType.h"
/**
*	@brief	���� 1���� �� Ŭ������ ������ �ʴ´�.

*/
class SimplifiedType	//���� �� Ÿ���� ������� �ʴ´�.
{
public:
	SimplifiedType() {
		S_Name = "";
		S_Number = -1;
	}//�⺻ ������
	~SimplifiedType() {}	//�⺻ �Ҹ���				���⼭ ����

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
		cout << "\t�� ��ȣ : " << S_Number << endl;
		cout << "\t�� �̸� : " << S_Name << endl;

	}
	/**
*	@brief	�� SimplifiedType�� Primary key�� ������ ����
*	@pre	���ϰ��� �ϴ� SimplifiedType�� �ʱ�ȭ �Ǿ��־����
*	@post	x
*	@param	data ���ϰ��� �ϴ� ������
*	@return	������� true, �ٸ���� false
*/
	bool operator==(SimplifiedType data)
	{

		if (this->getSongNum() == data.getSongNum())
			return true;
		else
			return false;
	}
	/**
*	@brief	�� SimplifiedType�� Primary key�� ũ�⸦ ����
*	@pre	���ϰ��� �ϴ� SimplifiedType�� �ʱ�ȭ �Ǿ��־����
*	@post	x
*	@param	data ���ϰ��� �ϴ� ������
*	@return	�º��� Ŭ��� true ������� false

*/
	bool operator>(SimplifiedType data)
	{
		if (this->getSongNum() > data.getSongNum())
			return true;
		else
			return false;
	}
	/**
*	@brief	�� SimplifiedType�� Primary key�� ũ�⸦ ����
*	@pre	���ϰ��� �ϴ� SimplifiedType�� �ʱ�ȭ �Ǿ��־����
*	@post	x
*	@param	data ���ϰ��� �ϴ� ������
*	@return	�캯�� Ŭ��� true ������� false
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
	int S_Number;		//�� ��ȣ
	string S_Name;		//���
//	MusicType* Mptr;	//���� �����ϱ� ���� ������

};

SimplifiedType SimplifiedType::operator=(const SimplifiedType& data)
{
	S_Number = data.S_Number;
	S_Name = data.S_Name;




	return *this;

}