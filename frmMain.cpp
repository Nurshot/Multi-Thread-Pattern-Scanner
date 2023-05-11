//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "frmMain.h"
#include <windows.h>
#include <psapi.h>
#include <processthreadsapi.h>
#include <processthreadsapi.h>
#include <vector>
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
	Application->OnException = AppException;
}
//---------------------------------------------------------------------------
AnsiString svuname="";

void __fastcall TMainForm::AppException(TObject *Sender, Exception *E)
{
	//Application->ShowException(E);
	//Application->Terminate();
	//return;
}
void __fastcall TMainForm::CreateParams(Controls::TCreateParams &Params)
{
	TForm::CreateParams(Params);
	Params.ExStyle   = Params.ExStyle | WS_EX_APPWINDOW;
  	Params.WndParent = ParentWindow;
}


MODULEINFO GetModuleInfo()
{
	MODULEINFO modinfo = { 0 };
	HMODULE hModule = GetModuleHandle(NULL);
	if (hModule == 0)
		return modinfo;
	GetModuleInformation(GetCurrentProcess(), hModule, &modinfo, sizeof(MODULEINFO));
	return modinfo;
}


bool Match(const char* pData, const char* bMask, const char* szMask)
{
	for (; *szMask; ++szMask, ++pData, ++bMask) {
		if (*szMask == 'x' && *pData != *bMask) {
			return false;
		}
	}
	return (*szMask) == NULL;
}

DWORD FindPattern(const char* bMask, const char* szMask)
{
	__try {
		MODULEINFO mInfo = GetModuleInfo();
		DWORD base = (DWORD)mInfo.lpBaseOfDll;
		DWORD size = (DWORD)mInfo.SizeOfImage;
		// You pattern scan code

		for (DWORD i = 0; i < size; i++) {
			if(MainForm->CheckBox1->Checked){
				__try
				{
					if (Match((char*)(base + i), bMask, szMask)) {
						return (DWORD)(base + i);
					}
				}
				__except (EXCEPTION_EXECUTE_HANDLER) {}
			}
			else{
                break;
            }
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {}


	return NULL;
}

std::vector<unsigned char> convert_string_to_bytes(const std::string& input) {
    std::vector<unsigned char> output;
    std::string::const_iterator it = input.begin();
    while (it != input.end()) {
        if (*it == '\\' && it + 1 != input.end() && *(it + 1) == 'x') {
            // Parse the hexadecimal digits following the "\x" prefix.
            if (it + 2 != input.end() && isxdigit(*(it + 2)) && it + 3 != input.end() && isxdigit(*(it + 3))) {
                output.push_back(static_cast<unsigned char>(std::stoi(std::string(it + 2, it + 4), nullptr, 16)));
                it += 4;
            } else {
                // Invalid "\x" prefix, treat it as a normal character.
                output.push_back('\\');
                ++it;
            }
        } else {
            output.push_back(static_cast<unsigned char>(*it));
            ++it;
        }
    }
    return output;
}

std::vector<char> convert_string_to_chars(const std::vector<unsigned char>& input) {
    std::vector<char> output(input.size());
    for (std::size_t i = 0; i < input.size(); ++i) {
        output[i] = static_cast<char>(input[i]);
    }
    return output;
}


DWORD WINAPI scanningpattern(){



    MainForm->Edit3->Text="Bekle";
	AnsiString k=    MainForm->Edit1->Text;

    AnsiString ke=    MainForm->Edit2->Text;

    std::vector<unsigned char> bytes = convert_string_to_bytes(k.c_str());
	std::vector<char> charData = convert_string_to_chars(bytes);



	const char* a1 =charData.data();
	const char* masked=ke.c_str();

	DWORD result = FindPattern(a1, masked);

	MainForm->Edit3->Text=IntToHex(StrToInt(result));
    return 0;
}

void __fastcall TMainForm::StartThread()
{

	CreateThread(0, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(scanningpattern), this, 0, NULL);

	
}


void __fastcall TMainForm::Button1Click(TObject *Sender)
{
	StartThread();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button2Click(TObject *Sender)
{
	MainForm->Edit1->Clear();
	MainForm->Edit2->Clear();
	MainForm->Edit3->Clear();
}
//---------------------------------------------------------------------------

