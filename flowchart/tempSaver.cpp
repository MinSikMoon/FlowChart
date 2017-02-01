#include "pch.h"
#include "TempSaver.h"
#include "App.xaml.h"

TempSaver::TempSaver()
{
	//0���� ����
	curVectorIndex = -1;
}

SIZE_TYPE TempSaver::getSize()
{
	return symbolInfoVectorContainer->Size;
}

void TempSaver::tempSave()
{
	//1. ������ ���� vector�����
	Vector<SymbolInfo^>^ clonedVector = ref new Vector<SymbolInfo^>();

	//2. symbolInfo ���� �� �־��ְ�
	for (SIZE_TYPE i = 0; i < App::symbolVector->Size; i++)
	{
		SymbolInfo^ symbolInfo = App::symbolVector->GetAt(i);
		clonedVector->Append(symbolInfo);
	}

	//3. clonedVector�� �־���.
	symbolInfoVectorContainer->Append(clonedVector);
	
	//4. curVectorIndex �÷��ֱ�
	
	curVectorIndex++;

	
}

void TempSaver::unDo()
{
	if (curVectorIndex > 0)
	{
		curVectorIndex--;
	}
}

void TempSaver::reDo()
{
	if (curVectorIndex < (symbolInfoVectorContainer->Size - 1))
	{
		curVectorIndex++;
	}
}

IVector<SymbolInfo^>^ TempSaver::getCurSymbolInfoVector()
{
	return symbolInfoVectorContainer->GetAt(curVectorIndex);
}
