#include "pch.h"
#include "TempSaver.h"
#include "App.xaml.h"

TempSaver::TempSaver()
{
	//-1�� ����
	curVectorIndex = -1;

	nowRowNum = 10;
	nowColumnNum = 10;

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
		clonedVector->Append(ref new SymbolInfo(symbolInfo));
	}

	if (curVectorIndex != symbolInfoVectorContainer->Size - 1)
	{
		symbolInfoVectorContainer->InsertAt(curVectorIndex+1,clonedVector);
		for (SIZE_TYPE i = 0; i < (symbolInfoVectorContainer->Size - curVectorIndex - 1); i++)
		{
			symbolInfoVectorContainer->RemoveAtEnd();
		}
		++curVectorIndex;
	
	}
	else
	{
		symbolInfoVectorContainer->Append(clonedVector);
		//. curVectorIndex �÷��ֱ�
		if (symbolInfoVectorContainer->Size > 0)
			curVectorIndex = symbolInfoVectorContainer->Size - 1;
		
	}

	
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
	wchar_t debugstr[256];
	swprintf_s(debugstr, L"������ : %d, curIndex: %d \n", symbolInfoVectorContainer->Size, curVectorIndex);
	OutputDebugString(debugstr);
	return symbolInfoVectorContainer->GetAt(curVectorIndex);
}

int TempSaver::getNowRowNum()
{
	return nowRowNum;
}

int TempSaver::getNowColumnNum()
{
	return nowColumnNum;
}

void TempSaver::setNowRowNum(int value)
{
	nowRowNum = value;
}

void TempSaver::setNowColumnNum(int value)
{
	nowColumnNum = value;
}
