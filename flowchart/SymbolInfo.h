#pragma once
#include <iostream>
#include <list>

using namespace std;
using namespace Platform;

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
	int symbolNo = 0;	// symbol�� ������ȣ
	int rowIndex, columnIndex;	// Grid ������ index
	//SymbolType symbolType;	// symbol�� ����
	// 1.process 2.decision 3.preparation 4.terminator 5.data 6. document
	int SymbolType = 0;	// symbol�� ����
	String^ title = nullptr;	// ����
	String^ content = nullptr;	// ����
	String^ detail = nullptr;	// ���γ���
	list<SymbolInfo^> path;
	//SymbolInfo^ path = nullptr;	// �� symbol�� ����Ű�� symbol��
public:
	SymbolInfo();

	// GET & SET
	int GetSymbolNo();
	void SetSymbolNo(int symbolNo);
	int GetRowIndex();
	void SetRowIndex(int rowIndex);
	int GetColumnIndex();
	void SetColumnIndex(int columnIndex);
	int GetSymbolType();
	void SetSymbolType(int SymbolType);
	String^ GetTitle();
	void SetTitle(String^ title);
	String^ GetContent();
	void SetContent(String^ content);
	String^ GetDetail();
	void SetDetail(String^ detail);
	list<SymbolInfo^> GetPath();
	void SetPath(list<SymbolInfo^> path);

	//SymbolInfo^ GetPath();
	//void SetPath(SymbolInfo^ path);
};
