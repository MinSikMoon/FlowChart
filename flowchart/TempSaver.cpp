#include "pch.h"
#include "TempSaver.h"
#include "App.xaml.h"

TempSaver::TempSaver()
{
	vectorPeekerIndex = -1; //1. vectorPeekerIndex�� -1��
	symbolInfoVectorContainer = ref new Vector< IVector< SymbolInfo^ >^ >();
}

SIZE_TYPE TempSaver::getSize()
{
	return symbolInfoVectorContainer->Size; //���� �����̳ʿ� ��� ����� �ֳ�?
}

void TempSaver::tempSave(PTR_COPIED_APP_VECTOR targetVector)
{
	PTR_COPIED_APP_VECTOR copiedAppVector = ref new Vector<SymbolInfo^>(); //1. ���ο� �ۺ��� ������ֱ�
																		 
	for (SIZE_TYPE i = 0; i < targetVector->Size; i++)  //2. symbolInfo ���� �� �־��ְ�
	{
		SymbolInfo^ symbolInfo = targetVector->GetAt(i);
		copiedAppVector->Append(ref new SymbolInfo(symbolInfo)); 
	}

	//���� App::Vector�� ī�ǹ����� ������ �Ǿ���. 
	symbolInfoVectorContainer->Append(copiedAppVector); //�����̳ʿ� �߰���Ų��.

	//peeker�ε��� ��������
	if (vectorPeekerIndex == symbolInfoVectorContainer->Size - 2)
	{
		vectorPeekerIndex;
	}
}

void TempSaver::unDo()
{
	if (vectorPeekerIndex > 0)
	{
		//0. container�ȿ��� ��Ŀ �ε��� ���� �ε��� ����Ű�� ���Ҹ� tempSaving�Ѵ�. 
		tempSave(symbolInfoVectorContainer->GetAt(--vectorPeekerIndex));
	}
}

void TempSaver::reDo()
{
	if (vectorPeekerIndex != symbolInfoVectorContainer->Size-1)
	{
		//0. container�ȿ��� ��Ŀ �ε��� ���� �ε��� ����Ű�� ���Ҹ� tempSaving�Ѵ�. 
		tempSave(symbolInfoVectorContainer->GetAt(++vectorPeekerIndex));
	}
}

void TempSaver::refreshPeekerIndex()
{
	vectorPeekerIndex = symbolInfoVectorContainer->Size - 1;
}

PTR_COPIED_APP_VECTOR TempSaver::getLastSymbolInfoVector()
{
	return symbolInfoVectorContainer->GetAt(symbolInfoVectorContainer->Size-1);
}

