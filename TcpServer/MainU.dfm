object MainF: TMainF
  Left = 0
  Top = 0
  Anchors = [akRight, akBottom]
  Caption = 'TCP'#49436#48260
  ClientHeight = 662
  ClientWidth = 1285
  Color = clBtnFace
  Constraints.MinHeight = 700
  Constraints.MinWidth = 1300
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object paForm: TPanel
    Left = 0
    Top = 0
    Width = 697
    Height = 662
    Align = alLeft
    Caption = 'FORM'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    object btSave: TButton
      Left = 240
      Top = 228
      Width = 209
      Height = 191
      Caption = 'SAVE'
      TabOrder = 0
      OnClick = btSaveClick
    end
  end
  object Panel2: TPanel
    Left = 697
    Top = 0
    Width = 588
    Height = 662
    Align = alClient
    Caption = 'Panel2'
    Color = 5789784
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentBackground = False
    ParentFont = False
    TabOrder = 1
    object cxPageControl1: TcxPageControl
      Left = 1
      Top = 1
      Width = 586
      Height = 660
      Align = alClient
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      Properties.ActivePage = cxTabSheet2
      Properties.CustomButtons.Buttons = <>
      LookAndFeel.NativeStyle = False
      LookAndFeel.SkinName = 'DarkSide'
      ClientRectBottom = 655
      ClientRectLeft = 2
      ClientRectRight = 581
      ClientRectTop = 25
      object cxTabSheet1: TcxTabSheet
        Caption = #51228#50612'(05)'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ImageIndex = 2
        ParentFont = False
        object rdBrightControl: TRadioGroup
          AlignWithMargins = True
          Left = 3
          Top = 182
          Width = 573
          Height = 50
          Margins.Top = 18
          Align = alTop
          BiDiMode = bdLeftToRight
          Caption = #48157#44592#51228#50612
          Color = 5789784
          Columns = 3
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clTeal
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          Items.Strings = (
            #49688#46041
            #51088#46041)
          ParentBiDiMode = False
          ParentColor = False
          ParentFont = False
          TabOrder = 0
        end
        object rdFanControl: TRadioGroup
          AlignWithMargins = True
          Left = 3
          Top = 253
          Width = 573
          Height = 50
          Margins.Top = 18
          Align = alTop
          BiDiMode = bdLeftToRight
          Caption = 'Fan '#51228#50612
          Columns = 3
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          Items.Strings = (
            #44732#51664
            #53020#51664
            #51088#46041)
          ParentBiDiMode = False
          ParentFont = False
          TabOrder = 1
        end
        object rdHeaterControl: TRadioGroup
          AlignWithMargins = True
          Left = 3
          Top = 324
          Width = 573
          Height = 50
          Margins.Top = 18
          Align = alTop
          BiDiMode = bdLeftToRight
          Caption = 'Heater '#51228#50612
          Columns = 3
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          Items.Strings = (
            #44732#51664
            #53020#51664
            #51088#46041)
          ParentBiDiMode = False
          ParentFont = False
          TabOrder = 2
        end
        object rdLampControl: TRadioGroup
          AlignWithMargins = True
          Left = 3
          Top = 395
          Width = 573
          Height = 50
          Margins.Top = 18
          Align = alTop
          BiDiMode = bdLeftToRight
          Caption = #46020#54805#49885' '#51204#46321#51228#50612
          Columns = 3
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          Items.Strings = (
            #44732#51664
            #53020#51664
            #51088#46041)
          ParentBiDiMode = False
          ParentFont = False
          TabOrder = 3
        end
        object rdLedControl: TRadioGroup
          AlignWithMargins = True
          Left = 3
          Top = 466
          Width = 573
          Height = 50
          Margins.Top = 18
          Align = alTop
          BiDiMode = bdLeftToRight
          Caption = 'LED '#51204#50896#51228#50612
          Columns = 3
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          Items.Strings = (
            #44732#51664
            #53020#51664
            #51088#46041)
          ParentBiDiMode = False
          ParentFont = False
          TabOrder = 4
        end
        object rdModulPower: TRadioGroup
          AlignWithMargins = True
          Left = 3
          Top = 537
          Width = 573
          Height = 50
          Margins.Top = 18
          Align = alTop
          BiDiMode = bdLeftToRight
          Caption = #51204#44305#54032' '#47784#46280#51204#50896#51228#50612
          Columns = 3
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          Items.Strings = (
            #44732#51664
            #53020#51664
            #51088#46041)
          ParentBiDiMode = False
          ParentFont = False
          TabOrder = 5
        end
        object Panel3: TPanel
          AlignWithMargins = True
          Left = 3
          Top = 18
          Width = 573
          Height = 143
          Margins.Top = 18
          Align = alTop
          BorderStyle = bsSingle
          Color = clMoneyGreen
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 6
          object lbResetTime: TLabel
            Left = 11
            Top = 17
            Width = 69
            Height = 13
            Caption = #51228#50612#44592' '#47532#49483#53944
            Color = clSkyBlue
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clNavy
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentColor = False
            ParentFont = False
            Transparent = True
          end
          object lbTryCount: TLabel
            Left = 243
            Top = 17
            Width = 69
            Height = 13
            Caption = #53685#49888#49884#46020' '#54943#49688
            Color = clSkyBlue
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clNavy
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentColor = False
            ParentFont = False
            Transparent = True
          end
          object lbControlTime: TLabel
            Left = 11
            Top = 58
            Width = 80
            Height = 13
            Caption = #51228#50612#44592' '#49884#44036#49483#53944
            Color = clSkyBlue
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clNavy
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentColor = False
            ParentFont = False
            Transparent = True
          end
          object lbRunTime: TLabel
            Left = 243
            Top = 58
            Width = 44
            Height = 13
            Caption = #50868#50689#49884#44036
            Color = clSkyBlue
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clNavy
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentColor = False
            ParentFont = False
            Transparent = True
          end
          object lbBlinkCycle: TLabel
            Left = 11
            Top = 98
            Width = 69
            Height = 13
            Caption = #51216#47736#49884#44036' '#51452#44592
            Color = clSkyBlue
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clNavy
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentColor = False
            ParentFont = False
            Transparent = True
          end
          object lbScinarioRunTime: TLabel
            Left = 243
            Top = 98
            Width = 91
            Height = 13
            Caption = #49884#45208#47532#50724' '#46041#51089#49884#44036
            Color = clSkyBlue
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clNavy
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentColor = False
            ParentFont = False
            Transparent = True
          end
          object edResetTime: TcxTextEdit
            Left = 96
            Top = 14
            TabOrder = 0
            Text = '?????'
            Width = 121
          end
          object edTryCount: TcxTextEdit
            Left = 352
            Top = 14
            TabOrder = 1
            Text = '3'
            Width = 121
          end
          object edControlTime: TcxTextEdit
            Left = 97
            Top = 54
            TabOrder = 2
            Text = '0000-00-00  00:00:00'
            Width = 121
          end
          object edBlinkCycle: TcxTextEdit
            Left = 97
            Top = 94
            TabOrder = 3
            Text = '0'
            Width = 121
          end
          object edRunTime: TcxTextEdit
            Left = 352
            Top = 54
            TabOrder = 4
            Text = '00:00 ~  00:00'
            Width = 121
          end
          object edScinarioRunTime: TcxTextEdit
            Left = 352
            Top = 94
            TabOrder = 5
            Text = '00:00:00'
            Width = 121
          end
        end
        object btSave05: TButton
          Left = 264
          Top = 593
          Width = 75
          Height = 25
          Caption = 'Save'
          TabOrder = 7
        end
      end
      object cxTabSheet2: TcxTabSheet
        Caption = #49345#53468'(06)'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ImageIndex = 1
        ParentFont = False
        object rdReStart: TRadioGroup
          AlignWithMargins = True
          Left = 3
          Top = 250
          Width = 573
          Height = 49
          Margins.Top = 10
          Align = alTop
          BiDiMode = bdLeftToRight
          Caption = #51116#49892#54665' '#50668#48512
          Columns = 3
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          Items.Strings = (
            #51221#49345
            #51116#49892#54665)
          ParentBiDiMode = False
          ParentFont = False
          TabOrder = 0
        end
        object rdFanState: TRadioGroup
          AlignWithMargins = True
          Left = 3
          Top = 374
          Width = 573
          Height = 49
          Margins.Top = 10
          Align = alTop
          BiDiMode = bdLeftToRight
          Caption = 'Fan '#49345#53468
          Columns = 3
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          Items.Strings = (
            'On'
            'Off'
            'Unknown')
          ParentBiDiMode = False
          ParentFont = False
          TabOrder = 1
        end
        object rdPowerError: TRadioGroup
          AlignWithMargins = True
          Left = 3
          Top = 560
          Width = 573
          Height = 49
          Margins.Top = 10
          Align = alTop
          BiDiMode = bdLeftToRight
          Caption = #51204#50896#47784#46280' '#51060#49345#50668#48512
          Columns = 3
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          Items.Strings = (
            #50640#47084#48156#49373
            #51221#49345
            'Unknown')
          ParentBiDiMode = False
          ParentFont = False
          TabOrder = 2
        end
        object Panel4: TPanel
          AlignWithMargins = True
          Left = 3
          Top = 10
          Width = 573
          Height = 41
          Margins.Top = 10
          Align = alTop
          BorderStyle = bsSingle
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 3
          object lbDisplayBright: TLabel
            Left = 184
            Top = 12
            Width = 58
            Height = 13
            Margins.Left = 50
            Caption = #54868#47732#51032' '#48157#44592
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clNavy
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
          end
          object lbTemperature: TLabel
            Left = 7
            Top = 12
            Width = 44
            Height = 13
            Margins.Left = 50
            Caption = #54632#52404#50728#46020
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clNavy
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
          end
          object lbEtc: TLabel
            Left = 383
            Top = 12
            Width = 22
            Height = 13
            Margins.Left = 50
            Caption = #44592#53440
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clNavy
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
          end
          object edTemperature: TcxTextEdit
            Left = 65
            Top = 8
            TabOrder = 0
            Text = '0'#176'C'
            Width = 96
          end
          object edDisplayBright: TcxTextEdit
            Left = 257
            Top = 8
            TabOrder = 1
            Text = '0%'
            Width = 96
          end
          object edEtc: TcxTextEdit
            Left = 425
            Top = 8
            TabOrder = 2
            Width = 96
          end
        end
        object rdModulError: TRadioGroup
          AlignWithMargins = True
          Left = 3
          Top = 498
          Width = 573
          Height = 49
          Margins.Top = 10
          Align = alTop
          BiDiMode = bdLeftToRight
          Caption = #47784#46280' '#51060#49345#50668#48512
          Columns = 3
          Items.Strings = (
            #50640#47084#48156#49373
            #51221#49345
            'Unknown')
          ParentBiDiMode = False
          TabOrder = 4
        end
        object rdFormKind: TRadioGroup
          AlignWithMargins = True
          Left = 3
          Top = 64
          Width = 573
          Height = 49
          Margins.Top = 10
          Align = alTop
          BiDiMode = bdLeftToRight
          Caption = #54364#52636' '#54268' '#51333#47448
          Columns = 3
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          Items.Strings = (
            #53685#49888' '#54268
            #46356#54260#53944' '#54268)
          ParentBiDiMode = False
          ParentFont = False
          TabOrder = 5
        end
        object rdOuterLampState: TRadioGroup
          AlignWithMargins = True
          Left = 3
          Top = 188
          Width = 573
          Height = 49
          Margins.Top = 10
          Align = alTop
          BiDiMode = bdLeftToRight
          Caption = #50808#48512#51312#47749' '#49345#53468
          Columns = 3
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          Items.Strings = (
            'On'
            'Off')
          ParentBiDiMode = False
          ParentFont = False
          TabOrder = 6
        end
        object rdHeaterState: TRadioGroup
          AlignWithMargins = True
          Left = 3
          Top = 436
          Width = 573
          Height = 49
          Margins.Top = 10
          Align = alTop
          BiDiMode = bdLeftToRight
          Caption = 'Heater '#49345#53468
          Columns = 3
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          Items.Strings = (
            'On'
            'Off'
            'Unknown')
          ParentBiDiMode = False
          ParentFont = False
          TabOrder = 7
        end
        object rdPowerState: TRadioGroup
          AlignWithMargins = True
          Left = 3
          Top = 126
          Width = 573
          Height = 49
          Margins.Top = 10
          Align = alTop
          BiDiMode = bdLeftToRight
          Caption = #51204#50896
          Columns = 3
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          Items.Strings = (
            'On'
            'Off')
          ParentBiDiMode = False
          ParentFont = False
          TabOrder = 8
        end
        object rdDoor: TRadioGroup
          AlignWithMargins = True
          Left = 3
          Top = 312
          Width = 573
          Height = 49
          Margins.Top = 10
          Align = alTop
          BiDiMode = bdLeftToRight
          Caption = 'Door'#49345#53468
          Columns = 3
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          Items.Strings = (
            'Open'
            'Close'
            'Unknown')
          ParentBiDiMode = False
          ParentFont = False
          TabOrder = 9
        end
        object btSave06: TButton
          Left = 256
          Top = 608
          Width = 75
          Height = 25
          Caption = 'Save'
          TabOrder = 10
        end
      end
      object cxTabSheet3: TcxTabSheet
        Caption = #47196#52972' '#49345#53468'(07)'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ImageIndex = 2
        ParentFont = False
        object rdOuterLampRun: TRadioGroup
          AlignWithMargins = True
          Left = 3
          Top = 298
          Width = 573
          Height = 49
          Margins.Top = 25
          Align = alTop
          BiDiMode = bdLeftToRight
          Caption = #50808#48512#51312#47749' '#46041#51089#50668#48512
          Columns = 3
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          Items.Strings = (
            #44732#51664
            #53020#51664
            #51088#46041)
          ParentBiDiMode = False
          ParentFont = False
          TabOrder = 0
        end
        object Panel5: TPanel
          AlignWithMargins = True
          Left = 3
          Top = 25
          Width = 573
          Height = 168
          Margins.Top = 25
          Align = alTop
          BorderStyle = bsSingle
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          object lbFanRunTemperature: TLabel
            Left = 51
            Top = 16
            Width = 87
            Height = 13
            Caption = 'Fan'#46041#51089#44060#49884' '#50728#46020
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clNavy
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
          end
          object lbEtc1: TLabel
            Left = 299
            Top = 97
            Width = 28
            Height = 13
            Caption = #44592#53440'1'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clNavy
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
          end
          object rdHeaterRunTemperature: TLabel
            Left = 51
            Top = 58
            Width = 102
            Height = 13
            Caption = 'Heater'#46041#51089#44060#49884' '#50728#46020
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clNavy
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
          end
          object lbBlinkCircle: TLabel
            Left = 299
            Top = 16
            Width = 91
            Height = 13
            Caption = #44636#48149#51060#45716' '#49884#44036#51452#44592
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clNavy
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
          end
          object lbLampRunBright: TLabel
            Left = 299
            Top = 58
            Width = 69
            Height = 13
            Caption = #51312#47749' '#46041#51089#48157#44592
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clNavy
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
          end
          object lbScinarioTransTime: TLabel
            Left = 51
            Top = 95
            Width = 91
            Height = 13
            Caption = #49884#45208#47532#50724' '#51204#54872#49884#44036
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clNavy
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
          end
          object lbEtc2: TLabel
            Left = 299
            Top = 129
            Width = 28
            Height = 13
            Caption = #44592#53440'2'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clNavy
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
          end
          object edFanRunTemperature: TcxTextEdit
            Left = 172
            Top = 13
            TabOrder = 0
            Text = '0'#176'C'
            Width = 93
          end
          object edHeaterRunTemperature: TcxTextEdit
            Left = 172
            Top = 55
            TabOrder = 1
            Text = '0'#176'C'
            Width = 93
          end
          object edLampRunBright: TcxTextEdit
            Left = 420
            Top = 55
            TabOrder = 2
            Text = '0%'
            Width = 93
          end
          object edEtc1: TcxTextEdit
            Left = 420
            Top = 92
            TabOrder = 3
            Width = 93
          end
          object edBlinkCircle: TcxTextEdit
            Left = 420
            Top = 13
            TabOrder = 4
            Text = '0'
            Width = 93
          end
          object edScinarioTransTime: TcxTextEdit
            Left = 172
            Top = 92
            TabOrder = 5
            Text = '00'
            Width = 93
          end
          object edEtc2: TcxTextEdit
            Left = 420
            Top = 124
            TabOrder = 6
            Width = 93
          end
        end
        object rdDisplayBright: TRadioGroup
          AlignWithMargins = True
          Left = 3
          Top = 221
          Width = 573
          Height = 49
          Margins.Top = 25
          Align = alTop
          BiDiMode = bdLeftToRight
          Caption = #54868#47732' '#48157#44592
          Columns = 3
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          Items.Strings = (
            #49688#46041
            #51088#46041)
          ParentBiDiMode = False
          ParentFont = False
          TabOrder = 2
        end
        object rdPowerControlMode: TRadioGroup
          AlignWithMargins = True
          Left = 3
          Top = 375
          Width = 573
          Height = 49
          Margins.Top = 25
          Align = alTop
          BiDiMode = bdLeftToRight
          Caption = #51204#50896#51228#50612' '#47784#46300
          Columns = 3
          Items.Strings = (
            #44732#51664
            #53020#51664
            #51088#46041)
          ParentBiDiMode = False
          TabOrder = 3
        end
        object rdFanRunMode: TRadioGroup
          AlignWithMargins = True
          Left = 3
          Top = 452
          Width = 573
          Height = 49
          Margins.Top = 25
          Align = alTop
          BiDiMode = bdLeftToRight
          Caption = 'Fan'#46041#51089#47784#46300
          Columns = 4
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          Items.Strings = (
            #44732#51664
            #53020#51664
            #51088#46041
            'Unknown')
          ParentBiDiMode = False
          ParentFont = False
          TabOrder = 4
        end
        object rdHeaterRunMode: TRadioGroup
          AlignWithMargins = True
          Left = 3
          Top = 529
          Width = 573
          Height = 49
          Margins.Top = 25
          Align = alTop
          BiDiMode = bdLeftToRight
          Caption = 'Heater'#46041#51089#47784#46300
          Columns = 4
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          Items.Strings = (
            #44732#51664
            #53020#51664
            #51088#46041
            'Unknown')
          ParentBiDiMode = False
          ParentFont = False
          TabOrder = 5
        end
        object btSave07: TButton
          Left = 256
          Top = 584
          Width = 75
          Height = 25
          Caption = 'Save'
          TabOrder = 6
        end
      end
    end
  end
  object IdTCPServer1: TIdTCPServer
    Bindings = <>
    DefaultPort = 5000
    Left = 24
    Top = 16
  end
end
