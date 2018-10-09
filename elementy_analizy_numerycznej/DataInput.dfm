object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 215
  ClientWidth = 164
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 24
    Width = 88
    Height = 13
    Caption = 'Liczba w'#281'z'#322#243'w - 1:'
  end
  object Label2: TLabel
    Left = 24
    Top = 85
    Width = 31
    Height = 13
    Caption = 'Label2'
  end
  object Label3: TLabel
    Left = 24
    Top = 151
    Width = 31
    Height = 13
    Caption = 'Label3'
  end
  object Edit1: TEdit
    Left = 16
    Top = 43
    Width = 121
    Height = 21
    TabOrder = 0
    OnKeyDown = Edit1KeyDown
  end
  object Edit2: TEdit
    Left = 16
    Top = 104
    Width = 121
    Height = 21
    TabOrder = 1
    OnKeyDown = Edit2KeyDown
  end
  object Edit3: TEdit
    Left = 16
    Top = 170
    Width = 121
    Height = 21
    TabOrder = 2
    OnKeyDown = Edit3KeyDown
  end
end
