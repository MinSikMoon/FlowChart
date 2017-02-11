#include "pch.h"
#include "HistoryObject.h"

HistoryObject::HistoryObject() {}

//�����丮�� �ʱ�ȭ��
void HistoryObject::initHistory()
{
	history[0] = ref new Vector<SymbolInfo^>();

	for (int i = 0; i < App::symbolVector->Size; i++)
	{
		SymbolInfo^ tempSymbolInfo = ref new SymbolInfo(App::symbolVector->GetAt(i));
		history[0]->Append(tempSymbolInfo);
	}

	for (int i = 1; i < 10; i++)
	{
		history[i] = nullptr;
	}
}

//�����丮 �ȿ� �ٲ� �ɺ����͸� ���� �־���
void HistoryObject::putHistory()
{
	historyIndex++;
	if (historyIndex >= 10)
	{
		moveFullHistory();
	}

	Vector<SymbolInfo^>^ tempHistoryElement = ref new Vector<SymbolInfo^>();
	for (int i = 0; i < App::symbolVector->Size; i++)
	{
		tempHistoryElement->Append(ref new SymbolInfo(App::symbolVector->GetAt(i)));
	}
	history[historyIndex] = tempHistoryElement;

	//undo�ϰ� ���� �ְ� redo�ϴ°� ������
	for (int i = historyIndex + 1; i < 10; i++)
	{
		history[i] = nullptr;
	}
}

//���
bool HistoryObject::unDo()
{
	//��� �� �� ������ ����
	if (historyIndex <= 0)
	{
		App::undoOrRedoButtonClicked = false;
		return false;
	}

	historyIndex--;
	Vector<SymbolInfo^>^ unDoSymbolVector = ref new Vector<SymbolInfo^>();
	for (int i = 0; i < history[historyIndex]->Size; i++)
	{
		unDoSymbolVector->Append(ref new SymbolInfo(history[historyIndex]->GetAt(i)));
	}
	App::symbolVector = unDoSymbolVector;

	return true;
}

//����
bool HistoryObject::reDo()
{
	//���� �� �� ������ ����
	if (historyIndex + 1 >= 10 || history[historyIndex + 1] == nullptr)
	{
		App::undoOrRedoButtonClicked = false;
		return false;
	}

	historyIndex++;
	Vector<SymbolInfo^>^ reDoSymbolVector = ref new Vector <SymbolInfo^>();
	for (int i = 0; i < history[historyIndex]->Size; i++)
	{
		reDoSymbolVector->Append(ref new SymbolInfo(history[historyIndex]->GetAt(i)));
	}
	App::symbolVector = reDoSymbolVector;

	return true;
}

//���� �����丮�� �ڸ� �����
void HistoryObject::moveFullHistory()
{
	for (int i = 1; i < 10; i++)
	{
		history[i - 1] = history[i];
	}
	history[9] = nullptr;

	historyIndex = 9;
}