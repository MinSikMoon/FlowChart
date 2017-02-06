#pragma once
#include <collection.h>
#include <algorithm>
#include "SymbolInfo.h"
#include "App.xaml.h"


using namespace flowchart;
using namespace Platform;
using namespace Platform::Collections;
using namespace Windows::Foundation::Collections;


typedef unsigned int SIZE_TYPE;
typedef IVector<SymbolInfo^>^ PTR_COPIED_APP_VECTOR;

ref class TempSaver sealed
{
public:
	TempSaver();

	SIZE_TYPE getSize(); // ���� �����̳ʿ� ���� ���纻�� � ����ִ°�?
	void tempSave(PTR_COPIED_APP_VECTOR targetVector); //�Ķ���ͷ� �Ѿ�� ���͸� �����Ѵ��� �����̳ʿ� �ִ´�. 
	void unDo(); //�ڷ�
	void reDo(); //������
	void refreshPeekerIndex(); //���ο� ���°� �ԷµǸ� PeekerIndex�� �ֽ����� �����ش�. 

	PTR_COPIED_APP_VECTOR getLastSymbolInfoVector(); //�����̳ʿ��� ���� ���纻 ������
	void containerRefresh(SIZE_TYPE maxHistoryCount); //���ʹ� �ε����� �����ǵ�, size�� ���Ӱ� ����������� �ʴ´�. ���� vector�� ���θ���� ���ҵ��� �־���� size�� ���ŵ�.

private:
	int vectorPeekerIndex; //�����̳ʸ� �Դٰ��� �ϸ� ���ϴ� �ɺ����͸� �����ִ� ������
	Vector< PTR_COPIED_APP_VECTOR >^ symbolInfoVectorContainer; // = ref new Vector< IVector< SymbolInfo^ >^ >();
	
};

