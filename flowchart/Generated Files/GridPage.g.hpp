﻿//------------------------------------------------------------------------------
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//------------------------------------------------------------------------------
#include "pch.h"

#if defined _DEBUG && !defined DISABLE_XAML_GENERATED_BINDING_DEBUG_OUTPUT
extern "C" __declspec(dllimport) int __stdcall IsDebuggerPresent();
#endif

#include "GridPage.xaml.h"

void ::flowchart::GridPage::InitializeComponent()
{
    if (_contentLoaded)
    {
        return;
    }
    _contentLoaded = true;
    ::Windows::Foundation::Uri^ resourceLocator = ref new ::Windows::Foundation::Uri(L"ms-appx:///GridPage.xaml");
    ::Windows::UI::Xaml::Application::LoadComponent(this, resourceLocator, ::Windows::UI::Xaml::Controls::Primitives::ComponentResourceLocation::Application);
}

void ::flowchart::GridPage::Connect(int __connectionId, ::Platform::Object^ __target)
{
    switch (__connectionId)
    {
        case 1:
            {
                this->RECTANGLE_STYLE = safe_cast<::Windows::UI::Xaml::Style^>(__target);
            }
            break;
        case 2:
            {
                this->BUTTON_STYLE_CONNECTOR = safe_cast<::Windows::UI::Xaml::Style^>(__target);
            }
            break;
        case 3:
            {
                this->BUTTON_STYLE_CONTENTS = safe_cast<::Windows::UI::Xaml::Style^>(__target);
            }
            break;
        case 4:
            {
                this->BUTTON_STYLE_DETAIL = safe_cast<::Windows::UI::Xaml::Style^>(__target);
            }
            break;
        case 5:
            {
                this->IMAGE_PROCESS = safe_cast<::Windows::UI::Xaml::Style^>(__target);
            }
            break;
        case 6:
            {
                this->IMAGE_DECISION = safe_cast<::Windows::UI::Xaml::Style^>(__target);
            }
            break;
        case 7:
            {
                this->IMAGE_PREPARATION = safe_cast<::Windows::UI::Xaml::Style^>(__target);
            }
            break;
        case 8:
            {
                this->IMAGE_TERMINATOR = safe_cast<::Windows::UI::Xaml::Style^>(__target);
            }
            break;
        case 9:
            {
                this->IMAGE_DATA = safe_cast<::Windows::UI::Xaml::Style^>(__target);
            }
            break;
        case 10:
            {
                this->IMAGE_DOCUMENT = safe_cast<::Windows::UI::Xaml::Style^>(__target);
            }
            break;
        case 11:
            {
                this->PageGrid = safe_cast<::Windows::UI::Xaml::Controls::Grid^>(__target);
                (safe_cast<::Windows::UI::Xaml::Controls::Grid^>(this->PageGrid))->DragOver += ref new ::Windows::UI::Xaml::DragEventHandler(this, (void (::flowchart::GridPage::*)
                    (::Platform::Object^, ::Windows::UI::Xaml::DragEventArgs^))&GridPage::PageGrid_DragOver);
                (safe_cast<::Windows::UI::Xaml::Controls::Grid^>(this->PageGrid))->Drop += ref new ::Windows::UI::Xaml::DragEventHandler(this, (void (::flowchart::GridPage::*)
                    (::Platform::Object^, ::Windows::UI::Xaml::DragEventArgs^))&GridPage::PageGrid_Drop);
            }
            break;
    }
    _contentLoaded = true;
}

::Windows::UI::Xaml::Markup::IComponentConnector^ ::flowchart::GridPage::GetBindingConnector(int __connectionId, ::Platform::Object^ __target)
{
    __connectionId;         // unreferenced
    __target;               // unreferenced
    return nullptr;
}


