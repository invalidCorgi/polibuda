object MainFrame: TMainFrame
  Left = 0
  Top = 0
  Caption = 'Wielomian interpolacyjny Newtona'
  ClientHeight = 336
  ClientWidth = 735
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
    Left = 552
    Top = 47
    Width = 20
    Height = 13
    Caption = 'x = '
  end
  object Label2: TLabel
    Left = 8
    Top = 87
    Width = 57
    Height = 18
    Caption = 'Wyniki:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object RadioGroup1: TRadioGroup
    Left = 344
    Top = 8
    Width = 186
    Height = 73
    Caption = 'Co powinno zosta'#263' obliczone'
    ItemIndex = 0
    Items.Strings = (
      'wsp'#243#322'czynniki'
      'warto'#347#263' dla x')
    TabOrder = 0
  end
  object Edit1: TEdit
    Left = 578
    Top = 44
    Width = 144
    Height = 21
    TabOrder = 1
    Text = '0'
  end
  object RadioGroup2: TRadioGroup
    Left = 8
    Top = 8
    Width = 313
    Height = 73
    Caption = 'Zastosowana arytmetyka'
    ItemIndex = 0
    Items.Strings = (
      'zmiennoprzecinkowa'
      'przedzia'#322'owa'
      'przedzia'#322'owa z danych w postaci przedzia'#322'owej')
    TabOrder = 2
    OnClick = RadioGroup2Click
  end
  object Button1: TButton
    Left = 552
    Top = 8
    Width = 89
    Height = 25
    Caption = 'Wprowad'#378' dane'
    TabOrder = 3
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 647
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Oblicz'
    TabOrder = 4
    OnClick = Button2Click
  end
  object Memo1: TMemo
    Left = 8
    Top = 104
    Width = 714
    Height = 224
    ScrollBars = ssVertical
    TabOrder = 5
  end
end
