#include "pch.h"
#include "TempSaver.h"
#include "App.xaml.h"

TempSaver::TempSaver()
{
	//1. ����� 0�̶��� ���� �����Ͱ� �ȵ��Դٴ� ��.
	curIdx = 0;
	startIdx = 0;
	endIdx = 0;
}

void TempSaver::tempSave(PTR_COPIED_APP_VECTOR targetVector)
{
	//1. copiedAppVector ����� : App::Vector�� ī�ǹ��� �����. 
	Vector<SymbolInfo^>^ copiedAppVector = ref new Vector<SymbolInfo^>();

	for (SIZE_TYPE i = 0; i < targetVector->Size; i++)  
	{
		SymbolInfo^ symbolInfo = targetVector->GetAt(i);
		copiedAppVector->Append(ref new SymbolInfo(symbolInfo)); 
	}
	copiedAppVector->VectorChanged += ref new Windows::Foundation::Collections::VectorChangedEventHandler<SymbolInfo ^>(this, &TempSaver::OnVectorChanged);

	//2. ó�� �����͸� �ִ��� �ƴ��� �Ǵ��ϰ� ���ο� �ε����� ��� �����ֱ�, curIdx�� ���纻�� �ִ´�. 
	if (curIdx == 0) //ó�� �����͸� �ִ� ����� ��� 1�� �����ش�. 
	{
		curIdx = 1;
		startIdx = 1;
		endIdx = 1;
	}
	else
	{
		if (next(curIdx) == startIdx) //�� �̻� ��������� ���ٴ� ��. ����ġ���.
		{
			startIdx = next(startIdx);
		}
		
		curIdx = next(curIdx);
		endIdx = curIdx;
	}
	
	symbolInfoVectorContainer[curIdx] = copiedAppVector;
	
}

SIZE_TYPE TempSaver::next(SIZE_TYPE targetIdx)
{
	if ((targetIdx / MAX_HISTORY) == 1) //���� �Դٴ� ��
	{
		return 1; //���⼭�� 0�� ó���� �ƴϴ�. 1�� ó����.
	}
	else
	{
		return targetIdx + 1;
	}
}

SIZE_TYPE TempSaver::previous(SIZE_TYPE targetIdx)
{
	if (targetIdx == 1) //���� �Դٴ� ��
	{
		return MAX_HISTORY; // �ε��� 1�̸� �� �ε����� ���� �ε���
	}
	else
	{
		return targetIdx - 1;
	}
}

void TempSaver::unDo()
{
	if (curIdx != startIdx)
		curIdx = previous(curIdx);
}

void TempSaver::reDo()
{
	if (curIdx != endIdx)
		curIdx = next(curIdx);
}

PTR_COPIED_APP_VECTOR TempSaver::getCurCopiedVector()
{
	return symbolInfoVectorContainer[curIdx];
}

void TempSaver::OnVectorChanged(Windows::Foundation::Collections::IObservableVector<SymbolInfo^>^ sender, Windows::Foundation::Collections::IVectorChangedEventArgs ^ event)
{
	App::tempSaver->tempSave(App::symbolVector); //���Ϳ� ��ȭ�� �����Ǹ� �ϴ� App::symbolVector �� ���������س��´�.
}



