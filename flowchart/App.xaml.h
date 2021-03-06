﻿//
// App.xaml.h
// App 클래스의 선언입니다.
//

#pragma once

#include "App.g.h"
#include "SymbolInfo.h"
#include <collection.h>



//typedef UINT64 LONGINT;

namespace flowchart
{
	
	/// <summary>
	/// 기본 응용 프로그램 클래스를 보완하는 응용 프로그램별 동작을 제공합니다.
	/// </summary>
	ref class App sealed
	{
	protected:
		virtual void OnLaunched(Windows::ApplicationModel::Activation::LaunchActivatedEventArgs^ e) override;

	internal:
		App();
		static property UINT64 symbolIdCount;
		static property int selectedSymbolNumber;
		static property Platform::Collections::Vector<SymbolInfo^>^ symbolVector;
		static property UINT64 draggingSymbolNo;
		static property int draggingSymbolType;
		static property int focusedSymbolIndex;	// 선택된 symbolInfoVector의 index

	public:
		//SymbolNo로 App::SymbolVector에서 SymbolInfo를 반환하는 함수
		static SymbolInfo^ getSymbolInfoByNo(UINT16 symbolNo);

	private:
		void OnSuspending(Platform::Object^ sender, Windows::ApplicationModel::SuspendingEventArgs^ e);
		void OnNavigationFailed(Platform::Object ^sender, Windows::UI::Xaml::Navigation::NavigationFailedEventArgs ^e);
	};
}
