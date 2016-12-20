#pragma once

using namespace Platform;

ref class SymbolInfo sealed
{
private:
	int symbolNo = 0;	// symbol�� ������ȣ
	int rowIndex, columnIndex;	// Grid ������ index
	SymbolType symbolType;	// symbol�� ����
	String^ title = nullptr;	// ����
	String^ content = nullptr;	// ����
	String^ detail = nullptr;	// ���γ���
	SymbolInfo^ path = nullptr;	// �� symbol�� ����Ű�� symbol��
public:
	SymbolInfo();
};

enum class SymbolType
{
	process,	// ó��
	decision,	// �Ǵ�
	preparation,	// �غ�
	terminator,	// �ܸ�
	data,	// �����
	document	// �μ�
};

