unit DataInput;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, IntervalArithmetic;

type
  TForm2 = class(TForm)
    Label1: TLabel;
    Edit1: TEdit;
    Label2: TLabel;
    Edit2: TEdit;
    Label3: TLabel;
    Edit3: TEdit;
    procedure Button1Click(Sender: TObject);
    procedure Edit2KeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
    procedure Edit1KeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
    procedure Edit3KeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form2: TForm2;
  n2 : Integer;
  n3 : Integer;
  n4 : Integer;
  n5 : Integer;
  nEntered : Boolean;
  xEntered : Boolean;
  fEntered : Boolean;

implementation

{$R *.dfm}
uses MainUnit;

procedure TForm2.Button1Click(Sender: TObject);
begin
  MainUnit.MainFrame.Edit1.Text := IntToStr(SizeOf(Extended));
end;

procedure TForm2.Edit1KeyDown(Sender: TObject; var Key: Word;
  Shift: TShiftState);
begin
  if Key = 13 then
  begin
    n := StrToInt(Edit1.Text);
    if numberType = 0 then
    begin
      SetLength(tabE[0], n+1);
      SetLength(tabE[1], n+1);
    end else
    begin
      SetLength(tabI[0], n+1);
      SetLength(tabI[1], n+1);
    end;
    MainFrame.Edit1.Text := IntToStr(n);
    Edit1.Text := '';
    if numberType = 2 then
    begin
      Label2.Caption := 'x[0].lewy=';
      Label3.Caption := 'f[0].prawy=';
    end else
    begin
      Label2.Caption := 'x[0]=';
      Label3.Caption := 'f[0]=';
    end;
    nEntered := True;
    SelectNext(ActiveControl, True, True);
  end;
end;

procedure TForm2.Edit2KeyDown(Sender: TObject; var Key: Word;
  Shift: TShiftState);
begin
  if (Key = 13) and (nEntered = True) and (n2 <= n) then
  begin
    if numberType = 0 then
    begin
      tabE[0][n2] := StrToFloat(Edit2.Text);
      n2 := n2 + 1;
      Label2.Caption := 'x['+IntToStr(n2)+']=';
    end else if numberType = 1 then
    begin
      tabI[0][n2] := int_read(Edit2.Text);
      n2 := n2 + 1;
      Label2.Caption := 'x['+IntToStr(n2)+']=';
    end else
    begin
      if n4 mod 2 = 0 then
      begin
        tabI[0][n2].a := left_read(Edit2.Text);
        Label2.Caption := 'x['+IntToStr(n2)+'].prawy=';
        n4 := n4 +1;
      end else
      begin
        tabI[0][n2].b := right_read(Edit2.Text);
        n2 := n2 + 1;
        Label2.Caption := 'x['+IntToStr(n2)+'].lewy=';
        n4 := n4 +1;
      end;
    end;
    Edit2.Text := '';
    MainUnit.MainFrame.UpdateMemo();
    if n2 = n+1 then
    begin
      SelectNext(ActiveControl, True, True);
      if n3 = n+1 then
      begin
        dataReady := True;
        Self.Close;
      end;
    end;
  end;
end;

procedure TForm2.Edit3KeyDown(Sender: TObject; var Key: Word;
  Shift: TShiftState);
begin
  if (Key = 13) and (nEntered = True) and (n3 <= n) then
  begin
    if numberType = 0 then
    begin
      tabE[1][n3] := StrToFloat(Edit3.Text);
      n3 := n3 + 1;
      Label3.Caption := 'f['+IntToStr(n3)+']=';
    end else if numberType = 1 then
    begin
      tabI[1][n3] := int_read(Edit3.Text);
      n3 := n3 + 1;
      Label3.Caption := 'f['+IntToStr(n3)+']=';
    end else
    begin
      if n5 mod 2 = 0 then
      begin
        tabI[1][n3].a := left_read(Edit3.Text);
        Label3.Caption := 'f['+IntToStr(n3)+'].prawy=';
        n5 := n5 +1;
      end else
      begin
        tabI[1][n3].b := right_read(Edit3.Text);
        n3 := n3 + 1;
        Label3.Caption := 'f['+IntToStr(n3)+'].lewy=';
        n5 := n5 +1;
      end;
    end;
    Edit3.Text := '';
    MainUnit.MainFrame.UpdateMemo();
    if n3 = n+1 then
    begin
      SelectNext(ActiveControl, True, True);
      if n2 = n+1 then
      begin
        dataReady := True;
        Self.Close;
      end;
    end;
  end;
end;

end.
