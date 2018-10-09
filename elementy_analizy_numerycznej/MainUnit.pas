unit MainUnit;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, Vcl.ExtCtrls, IntervalArithmetic, DataInput,
  NewtonCoefficientsAndValues, NewtonCoefficientsAndValuesInterval;

type
  TMainFrame = class(TForm)
    RadioGroup1: TRadioGroup;
    Edit1: TEdit;
    Label1: TLabel;
    RadioGroup2: TRadioGroup;
    Button1: TButton;
    Button2: TButton;
    Memo1: TMemo;
    Label2: TLabel;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure RadioGroup2Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  MainFrame: TMainFrame;
  n : Integer;
  tabE : Array[0..1] of TArray<Extended>;
  tabI : Array[0..1] of TArray<interval>;
  dataReady : Boolean = False;
  numberType : Byte = 0;

implementation

{$R *.dfm}

var outCoefficientsExtended : TArray<Extended>;
    outValueExtended : Extended;
    pointExtended : Extended;
    outCoefficientsInterval : TArray<Interval>;
    outValueInterval : Interval;
    pointInterval : interval;
    st : Integer;

procedure TMainFrame.Button1Click(Sender: TObject);
begin
  n2 := 0;
  n3 := 0;
  n4 := 0;
  n5 := 0;
  numberType := RadioGroup2.ItemIndex;
  dataReady := False;
  if numberType <> 2 then
  begin
    DataInput.Form2.Label2.Caption := 'x[0]=';
    DataInput.Form2.Label3.Caption := 'f[0]=';
  end else
  begin
    DataInput.Form2.Label2.Caption := 'x[0].lewy=';
    DataInput.Form2.Label3.Caption := 'f[0].lewy=';
  end;
  DataInput.Form2.ShowModal;
end;

procedure TMainFrame.Button2Click(Sender: TObject);
var i : Integer;
    left, right : string;
begin
  if dataReady = False then
  begin
    ShowMessage('Nie zostały wprowadzone dane');
  end else
    begin
    if numberType = 0 then
    begin
      if RadioGroup1.ItemIndex = 0 then
      begin
        SetLength(outCoefficientsExtended, Length(tabE[1]));
        outCoefficientsExtended := NewtonCoefficientsExtended(n, tabE[0], tabE[1], st);
        case st of
          0:begin
              Memo1.Text := 'Współczynniki wielomianu od największego wykładnika:' + sLineBreak;
              for i:=Low(outCoefficientsExtended) to High(outCoefficientsExtended) do
              begin
                Memo1.Text := Memo1.Text + 'a['+IntToStr(i)+']=' + StringReplace(FloatToStrF(outCoefficientsExtended[i], ffExponent, 17, 4),',','.',[rfReplaceAll]) + sLineBreak;
              end;
            end;
          1:Memo1.Text := 'liczba węzłow nie jest dodatnia';
          2:Memo1.Text := 'istnieją dwa takie same x';
        end;
      end else
      begin
        pointExtended := StrToFloat(Edit1.Text);
        outValueExtended := NewtonValueExtended(n, tabE[0], tabE[1], pointExtended, st);
        case st of
          0:Memo1.Text := 'Wartość dla x=' + StringReplace(FloatToStrF(pointExtended, ffExponent, 17, 4)+ ':' + sLineBreak + FloatToStrF(outValueExtended, ffExponent, 17, 4),',','.',[rfReplaceAll]);
          1:Memo1.Text := 'liczba węzłow nie jest dodatnia';
          2:Memo1.Text := 'istnieją dwa takie same x';
        end;
      end;
    end else
    begin
      if RadioGroup1.ItemIndex = 0 then
      begin
        SetLength(outCoefficientsInterval, Length(tabI[1]));
        outCoefficientsInterval := NewtonCoefficientsInterval(n, tabI[0], tabI[1], st);
        case st of
          0:begin
            Memo1.Text := 'Współczynniki wielomianu od największego wykładnika:' + sLineBreak;
            for i:=Low(outCoefficientsInterval) to High(outCoefficientsInterval) do
            begin
              iends_to_strings(outCoefficientsInterval[i],left, right);
              Memo1.Text := Memo1.Text + 'a['+IntToStr(i)+']=[' + left;
              Memo1.Text := Memo1.Text + ', ' + right + ']' + sLineBreak;
              Memo1.Text := Memo1.Text + 'szerokość przedziału a['+IntToStr(i)+']=' + StringReplace(FloatToStrF(int_width(outCoefficientsInterval[i]), ffExponent, 4, 4),',','.',[rfReplaceAll]) + sLineBreak;
            end;
          end;
          1:Memo1.Text := 'liczba węzłow nie jest dodatnia';
          2:Memo1.Text := 'istnieją dwa takie same x';
        end;
      end else
      begin
        pointInterval := int_read(Edit1.Text);
        outValueInterval := NewtonValueInterval(n, tabI[0], tabI[1], pointInterval, st);
        case st of
          0:begin
            iends_to_strings(pointInterval,left,right);
            Memo1.Text := 'Wartość dla x:' + sLineBreak + '[' + left;
            Memo1.Text := Memo1.Text + ', ' + right + ']' + sLineBreak;
            Memo1.Text := Memo1.Text + 'szerokość przedziału x=' + StringReplace(FloatToStrF(int_width(pointInterval), ffExponent, 4, 4),',','.',[rfReplaceAll]) + sLineBreak + sLineBreak;

            iends_to_strings(outValueInterval,left,right);
            Memo1.Text := Memo1.Text + 'Wynosi:' + sLineBreak + '[' + left;
            Memo1.Text := Memo1.Text + ', ' + right + ']' + sLineBreak;
            Memo1.Text := Memo1.Text + 'szerokość przedziału x=' + StringReplace(FloatToStrF(int_width(outValueInterval), ffExponent, 4, 4),',','.',[rfReplaceAll]);
          end;
          1:Memo1.Text := 'liczba węzłow nie jest dodatnia';
          2:Memo1.Text := 'istnieją dwa takie same x';
        end;
      end;
    end;
  end;
end;

procedure TMainFrame.RadioGroup2Click(Sender: TObject);
begin

  numberType := RadioGroup2.ItemIndex;
  dataReady := false;

end;

end.
