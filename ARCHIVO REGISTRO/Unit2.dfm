object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 378
  ClientWidth = 832
  Color = clCream
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 247
    Top = 32
    Width = 144
    Height = 19
    Caption = 'ABM Alumnos.dat'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 125
    Top = 91
    Width = 56
    Height = 19
    Caption = 'Codigo'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 114
    Top = 125
    Width = 64
    Height = 19
    Caption = 'Nombre'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 103
    Top = 158
    Width = 75
    Height = 19
    Caption = 'Direccion'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label5: TLabel
    Left = 11
    Top = 193
    Width = 167
    Height = 19
    Caption = 'Fecha de nacimiento'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Button1: TButton
    Left = 152
    Top = 280
    Width = 99
    Height = 25
    Caption = 'Guardar'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 272
    Top = 280
    Width = 91
    Height = 25
    Caption = 'Eliminar'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 385
    Top = 280
    Width = 90
    Height = 25
    Caption = 'Limpiar'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
  end
  object Edit1: TEdit
    Left = 191
    Top = 88
    Width = 370
    Height = 27
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 3
    OnExit = Edit1Exit
    OnKeyPress = Edit1KeyPress
  end
  object Edit2: TEdit
    Left = 191
    Top = 121
    Width = 370
    Height = 27
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 4
    OnKeyPress = Edit2KeyPress
  end
  object Edit3: TEdit
    Left = 191
    Top = 155
    Width = 370
    Height = 27
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 5
  end
  object Edit4: TEdit
    Left = 191
    Top = 188
    Width = 26
    Height = 27
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 6
    OnKeyPress = Edit4KeyPress
  end
  object Edit5: TEdit
    Left = 223
    Top = 188
    Width = 26
    Height = 27
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 7
    OnKeyPress = Edit5KeyPress
  end
  object Edit6: TEdit
    Left = 255
    Top = 188
    Width = 26
    Height = 27
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 8
    OnKeyPress = Edit6KeyPress
  end
  object Button4: TButton
    Left = 648
    Top = 14
    Width = 75
    Height = 25
    Caption = 'NavegarIdx'
    TabOrder = 9
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 600
    Top = 54
    Width = 75
    Height = 25
    Caption = '<<'
    Enabled = False
    TabOrder = 10
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 696
    Top = 54
    Width = 75
    Height = 25
    Caption = '>>'
    Enabled = False
    TabOrder = 11
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 648
    Top = 85
    Width = 75
    Height = 25
    Caption = 'Fin'
    Enabled = False
    TabOrder = 12
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 504
    Top = 282
    Width = 75
    Height = 25
    Caption = 'Abrir'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 13
    OnClick = Button8Click
  end
  object Memo1: TMemo
    Left = 567
    Top = 144
    Width = 185
    Height = 89
    Lines.Strings = (
      'Memo1')
    TabOrder = 14
  end
  object Button9: TButton
    Left = 600
    Top = 280
    Width = 75
    Height = 25
    Caption = 'Guaradar'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 15
    OnClick = Button9Click
  end
  object MainMenu1: TMainMenu
    Left = 8
    Top = 16
    object Indices1: TMenuItem
      Caption = 'Indices'
      object porcodigo1: TMenuItem
        Caption = 'por codigo'
        OnClick = porcodigo1Click
      end
      object pornombre1: TMenuItem
        Caption = 'por nombre'
      end
    end
    object Ordenar1: TMenuItem
      Caption = 'Ordenar'
      object porcodigo2: TMenuItem
        Caption = 'por codigo'
        OnClick = porcodigo2Click
      end
      object porcodigo3: TMenuItem
        Caption = 'por nombre'
      end
    end
  end
  object openTxtDlg: TOpenTextFileDialog
    Left = 48
    Top = 24
  end
  object saveTxtDlg: TSaveTextFileDialog
    Left = 104
    Top = 24
  end
end
