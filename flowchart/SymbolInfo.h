#pragma once
#include <collection.h>
#include <algorithm>

using namespace std;
using namespace Platform;
using namespace Platform::Collections;
using namespace Windows::Foundation::Collections;

ref class SymbolInfo sealed
{
	//enum class SymbolType
	//{
	//	process,	// ó��
	//	decision,	// �Ǵ�
	//	preparation,	// �غ�
	//	terminator,	// �ܸ�
	//	data,	// �����
	//	document	// �μ�
	//};
private:

	UINT64 symbolNo = 0;	// symbol�� ������ȣ
	int rowIndex, columnIndex;	// Grid ������ index
	// 1.process 2.decision 3.preparation 4.terminator 5.data 6. document
	int symbolType = 0;	// symbol�� ����
	String^ title = nullptr;	// ����
	String^ content = nullptr;	// ����
	String^ detail = nullptr;	// ���γ���
	Vector<SymbolInfo^>^ path = ref new Vector<SymbolInfo^>();	// ��� (�������)
public:
	SymbolInfo();

	// GET & SET


	property UINT64 SymbolNo
	{
		UINT64 get() { return symbolNo; }
		void set(UINT64 value) { symbolNo = value; }
	}
	property int RowIndex
	{
		int get() { return rowIndex; }
		void set(int value) { rowIndex = value; }
	}
	property int ColumnIndex
	{
		int get() { return columnIndex; }
		void set(int value) { columnIndex = value; }
	}
	property int SymbolType
	{
		int get() { return symbolType; }
		void set(int value) { symbolType = value; }
	}
	property String^ Title
	{
		String^ get() { return title; }
		void set(String^ value) { title = value; }
	}
	property String^ Content
	{
		String^ get() { return content; }
		void set(String^ value) { content = value; }
	}
	property String^ Detail
	{
		String^ get() { return detail; }
		void set(String^ value) { detail = value; }
	}
	property IVector<SymbolInfo^>^ Path
	{
		IVector<SymbolInfo^>^ get() 
		{
			return path;
		}
		//void set(IVector<SymbolInfo^>^ value)
		//{
		//	path = static_cast<Vector>(value);
		//}
	}
};
