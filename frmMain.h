//---------------------------------------------------------------------------

#ifndef frmMainH
#define frmMainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit1;
	TEdit *Edit2;
	TLabel *Label1;
	TLabel *Label2;
	TButton *Button1;
	TLabel *Label3;
	TEdit *Edit3;
	TCheckBox *CheckBox1;
	TButton *Button2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall StartThread();
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall CreateParams(Controls::TCreateParams &Params);
private:	// User declarations
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
    void __fastcall AppException(TObject *Sender, Exception *E);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
