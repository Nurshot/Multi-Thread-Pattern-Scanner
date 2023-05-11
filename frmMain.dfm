object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = 'MainForm'
  ClientHeight = 265
  ClientWidth = 628
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Label1: TLabel
    Left = 24
    Top = 59
    Width = 41
    Height = 15
    Caption = 'Pattern:'
  end
  object Label2: TLabel
    Left = 24
    Top = 104
    Width = 31
    Height = 15
    Caption = 'Mask:'
  end
  object Label3: TLabel
    Left = 136
    Top = 171
    Width = 36
    Height = 15
    Caption = 'Sonuc:'
  end
  object Edit1: TEdit
    Left = 71
    Top = 56
    Width = 513
    Height = 23
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 71
    Top = 101
    Width = 513
    Height = 23
    TabOrder = 1
  end
  object Button1: TButton
    Left = 178
    Top = 216
    Width = 225
    Height = 25
    Caption = 'Scan Pattern'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Edit3: TEdit
    Left = 178
    Top = 168
    Width = 225
    Height = 23
    TabOrder = 3
  end
  object CheckBox1: TCheckBox
    Left = 110
    Top = 220
    Width = 62
    Height = 17
    Caption = 'Aktif'
    Checked = True
    State = cbChecked
    TabOrder = 4
  end
  object Button2: TButton
    Left = 264
    Top = 25
    Width = 75
    Height = 25
    Caption = 'Clear'
    TabOrder = 5
    OnClick = Button2Click
  end
end
