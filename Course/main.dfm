object Form1: TForm1
  Left = 250
  Top = 20
  Caption = #1051#1072#1073#1080#1088#1080#1085#1090
  ClientHeight = 661
  ClientWidth = 984
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 24
    Top = 8
    Width = 689
    Height = 585
    OnMouseDown = Image1MouseDown
  end
  object RadioGroup1: TRadioGroup
    Left = 736
    Top = 16
    Width = 207
    Height = 105
    Caption = #1044#1077#1081#1089#1090#1074#1080#1077
    ItemIndex = 0
    Items.Strings = (
      #1055#1086#1089#1090#1088#1086#1077#1085#1080#1077' '#1083#1072#1073#1080#1088#1080#1085#1090#1072
      #1042#1099#1073#1086#1088' '#1085#1072#1095#1072#1083#1100#1085#1086#1081' '#1090#1086#1095#1082#1080
      #1042#1099#1073#1086#1088' '#1082#1086#1085#1077#1095#1085#1086#1081' '#1090#1086#1095#1082#1080)
    TabOrder = 0
  end
  object Button2: TButton
    Left = 868
    Top = 303
    Width = 75
    Height = 50
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 736
    Top = 303
    Width = 87
    Height = 50
    Caption = #1053#1072#1081#1090#1080' '#1087#1091#1090#1100
    TabOrder = 2
    WordWrap = True
    OnClick = Button3Click
  end
  object GroupBox1: TGroupBox
    Left = 736
    Top = 136
    Width = 207
    Height = 129
    Caption = #1056#1072#1079#1084#1077#1088#1099' '#1083#1072#1073#1080#1088#1080#1085#1090#1072
    TabOrder = 3
    object Label1: TLabel
      Left = 18
      Top = 32
      Width = 80
      Height = 13
      Caption = #1055#1086' '#1075#1086#1088#1080#1079#1086#1085#1090#1072#1083#1080
    end
    object Label2: TLabel
      Left = 28
      Top = 59
      Width = 70
      Height = 13
      Caption = #1055#1086' '#1074#1077#1088#1090#1080#1082#1072#1083#1080
    end
    object Edit1: TEdit
      Left = 114
      Top = 29
      Width = 84
      Height = 21
      NumbersOnly = True
      TabOrder = 0
    end
    object Edit2: TEdit
      Left = 114
      Top = 56
      Width = 84
      Height = 21
      NumbersOnly = True
      TabOrder = 1
    end
    object Button1: TButton
      Left = 16
      Top = 91
      Width = 129
      Height = 25
      Caption = #1055#1086#1089#1090#1088#1086#1080#1090#1100' '#1083#1072#1073#1080#1088#1080#1085#1090
      TabOrder = 2
      OnClick = Button1Click
    end
  end
end
