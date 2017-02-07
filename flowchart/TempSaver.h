#pragma once
#include <collection.h>
#include <algorithm>
#include "SymbolInfo.h"
#include "App.xaml.h"


using namespace flowchart;
using namespace Platform;
using namespace Platform::Collections;
using namespace Windows::Foundation::Collections;

#define MAX_HISTORY 5 //�����丮 ���� �ɷ�

typedef unsigned int SIZE_TYPE;
typedef IVector<SymbolInfo^>^ PTR_COPIED_APP_VECTOR;

ref class TempSaver sealed
{

public:
	TempSaver();

	void tempSave(PTR_COPIED_APP_VECTOR targetVector); //�Ķ���ͷ� �Ѿ�� ���͸� �����Ѵ��� �����̳ʿ� �ִ´�. 
	
	SIZE_TYPE next(SIZE_TYPE targetIdx);
	SIZE_TYPE previous(SIZE_TYPE targetIdx);
	
	void unDo(); //�ڷ�
	void reDo(); //������

	PTR_COPIED_APP_VECTOR getCurCopiedVector();
		
private:
	PTR_COPIED_APP_VECTOR symbolInfoVectorContainer[MAX_HISTORY + 1];
	SIZE_TYPE curIdx, startIdx, endIdx;
	void OnVectorChanged(Windows::Foundation::Collections::IObservableVector<SymbolInfo ^> ^sender, Windows::Foundation::Collections::IVectorChangedEventArgs ^event);
};

