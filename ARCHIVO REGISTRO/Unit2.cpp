//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	openTxtDlg = new TOpenTextFileDialog(this);
	saveTxtDlg = new TSaveTextFileDialog(this);

	// Create a new string list that holds encoding information.
	TStrings* encodings = new TStringList();

	// Add some encodings to the list.
	encodings->AddObject("ASCII", TEncoding::ASCII);
	encodings->AddObject("UNICODE", TEncoding::Unicode);
	encodings->AddObject("UTF8", TEncoding::UTF8);

	openTxtDlg->Encodings->Assign(encodings);
	saveTxtDlg->Encodings->Assign(encodings);

	openTxtDlg->Filter = "Text files (*.txt)|*.TXT|XML files (*.xml)|*.XML|Any file (*.*)|*.*";
	saveTxtDlg->Filter = "Text files (*.txt)|*.TXT|XML files (*.xml)|*.XML|Any file (*.*)|*.*";
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
	nomArch="Alumnos.dat";
	nomIdxCod="codi.idx";
   pf=new fstream(nomArch.c_str(),ios::in|ios::binary);
   if (pf-> fail()) {
	   delete(pf);
	   pf = new fstream(nomArch.c_str(),ios::out|ios::binary);
   }
   pf->close();
   delete(pf);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
  /*	  pf->flush();
	  pf->close();
	  delete pf;  */
}
//---------------------------------------------------------------------------
 bool EliminarNum(char z){
AnsiString vocales = "123456789";
	return vocales.Pos(z)>0;
}
void EliminarNumCad(String &x){
	if(x!=""){
		char z = x[1];
		x.Delete(1,1);
		EliminarNumCad(x);
		if(!EliminarNum(z)){
			x = String(z) + x;
		}
	}
}
bool EliminarLetra(char z){
AnsiString vocales = "ABCDEFGHIJKLMNOPQRSTUVWXYZ�abcdefghijklmnopqrsuvwxyz�";
	return vocales.Pos(z)>0;
}
void EliminarLetCad(String &x){
	if(x!=""){
		char z = x[1];
		x.Delete(1,1);
		EliminarLetCad(x);
		if(!EliminarLetra(z)){
			x = String(z) + x;
		}
	}
}

void __fastcall TForm2::Edit1KeyPress(TObject *Sender, System::WideChar &Key)
{

	if ((Key>=32&& Key<=47)||(Key>=58 && Key<=255)) {

		 ShowMessage("ERROR SOLO DEBE INTRODUCIR NUMEROS");
		 Key=0;
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edit2KeyPress(TObject *Sender, System::WideChar &Key)
{
	 if ((Key>=33 && Key<=64)||(Key>=91 && Key<=96)||(Key>=123 && Key<=255)) {
		  ShowMessage("ERROR SOLO DEBEN INTRODUCIR LETRAS");
		  Key=0;
	}

}
//---------------------------------------------------------------------------




void __fastcall TForm2::Edit4KeyPress(TObject *Sender, System::WideChar &Key)
{
	if ((Key>=33&& Key<=47)||(Key>=58 && Key<=255)) {

		 ShowMessage("ERROR SOLO DEBE INTRODUCIR NUMEROS");
		 Key=0;
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Edit5KeyPress(TObject *Sender, System::WideChar &Key)
{
		if ((Key>=33&& Key<=47)||(Key>=58 && Key<=255)) {

		 ShowMessage("ERROR SOLO DEBE INTRODUCIR NUMEROS");
		 Key=0;
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edit6KeyPress(TObject *Sender, System::WideChar &Key)
{
	if ((Key>=33&& Key<=47)||(Key>=58 && Key<=255)) {

		 ShowMessage("ERROR SOLO DEBE INTRODUCIR NUMEROS");
		 Key=0;
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
bool hallado= false;
AnsiString cad;
RegAlumno reg,regNuevo;
regNuevo.mark='0';//no marcado para borrar
regNuevo.cod=StrToInt(Edit1->Text);
cad=Edit2->Text;
strcpy(regNuevo.nom,cad.c_str());
cad=Edit3->Text;
strcpy(regNuevo.dir,cad.c_str());
regNuevo.fecha.dia=StrToInt(Edit4->Text);
regNuevo.fecha.mes=StrToInt(Edit5->Text);
regNuevo.fecha.a�o=StrToInt(Edit6->Text);
pf=new fstream(nomArch.c_str(),ios::in|ios::out|ios::binary);
 if (pf->is_open()) {
	 do{
		pf->read((char *)&reg,sizeof(reg));
	   hallado=(reg.cod==regNuevo.cod)&&(reg.mark!='*');
	 }while(!hallado && !pf->eof());
	 if (hallado) {
		 pf->seekg(-sizeof(reg),ios::cur);
	 }else{
		 pf->seekg(0,ios::end);
	 }
	pf->write((char *)&regNuevo,sizeof(regNuevo));
	Edit1->Text=""; Edit2->Text=""; Edit3->Text=""; Edit4->Text=""; Edit5->Text=""; Edit6->Text="" ;
	Edit1->SetFocus();
	pf->close();
 }
 pf->flush();
 delete pf;
}

Cardinal StrtoInt(AnsiString cad)
{
	Cardinal nu=0;
	for (byte i = 1; i<=cad.Length(); i++) {
		if ((cad[i]>='0')&&(cad[i]<='9')) {
			nu=nu*10+cad[i]-48;
		}
	}
	return nu;
}

void __fastcall TForm2::Edit1Exit(TObject *Sender)
{
 bool hallado=false;
 RegAlumno reg;
 Word codi;
 codi=StrtoInt(Edit1->Text);
 pf=new fstream(nomArch.c_str(),ios::in|ios::binary);
  if (pf->is_open()) {
	do{//buscar el codigo archivo
	  pf->read((char*)&reg,sizeof(reg));
	  hallado=(reg.cod==codi)&&(reg.mark!='*');
	}while(!hallado && !pf->eof());
	if (hallado){ //si lo encuentra, pone los datos en pantalla
	Edit2->Text=reg.nom;
	Edit3->Text=reg.dir;
	Edit4->Text=reg.fecha.dia;
	Edit5->Text=reg.fecha.mes;
	Edit6->Text=reg.fecha.a�o;
	Edit2->SetFocus();
	}else{        // si no,limpia la pantalla
	Edit2->Text="";
	Edit3->Text="";
	Edit4->Text="";
	Edit5->Text="";
	Edit6->Text="";
	}
  }
   pf->close();
   delete(pf);
}



//---------------------------------------------------------------------------

//---------------------------------------------------------------------------


void __fastcall TForm2::Button2Click(TObject *Sender)
{
 bool hallado=false;
 RegAlumno reg;
 Word cod;
 reg.mark='0';
 cod=StrToInt(Edit1->Text);
 pf=new fstream(nomArch.c_str(),ios::in|ios::out|ios::binary);
  if (pf->is_open()) {
	do{
	  pf->read((char*)&reg,sizeof(reg));
	  hallado=(reg.cod==cod)&&(reg.mark!='*');
	}while(!hallado && !pf->eof());
	if (hallado){
		reg.mark='*';   //marcado como borrrado
		pf->seekg(-sizeof(reg),ios::cur);
		pf->write((char *)&reg,sizeof(reg));
		Edit2->Text="";
		Edit3->Text="";
		Edit4->Text="";
		Edit5->Text="";
		Edit6->Text="";
		Edit1->Text="";
		Edit1->SetFocus();
	}
  }
   pf->close();
   delete(pf);
}
//---------------------------------------------------------------------------


void __fastcall TForm2::porcodigo1Click(TObject *Sender)
{
	RegAlumno reg;
	RegIdxCod regIdx;
	fstream pix(nomIdxCod.c_str(),ios::out|ios::trunc|ios::binary);
	pf=new fstream(nomArch.c_str(),ios::in|ios::out|ios::binary);
	do{
		 regIdx.pos=pf->tellp();
		 pf->read((char *)&reg,sizeof(reg));
		 if (!pf->fail())  {
			regIdx.cod=reg.cod;
			pix.write((char *)&regIdx,sizeof(regIdx));

		 }
	}while(!pf->eof());
	pf->close();
	delete(pf);
	pix.flush();
	pix.close();

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button4Click(TObject *Sender)
{
	RegIdxCod reg;
	RegAlumno regA;
	Button5->Enabled=true;
	Button6->Enabled=true;
	Button7->Enabled=true;
	pf=new fstream(nomArch.c_str(),ios::in|ios::binary);
	pIdx =new fstream(nomIdxCod.c_str(),ios::in|ios::binary);
	if (pIdx->is_open()) {
		pIdx->read((char*)&reg,sizeof(reg));
		if (!pIdx->eof()) {
		 pf->seekp(reg.pos,ios::beg);
		 pf->read((char*)&regA,sizeof(regA));
		 Edit1->Text=regA.cod;
		 Edit2->Text=regA.nom;
		 Edit3->Text=regA.dir;
		 Edit4->Text=regA.fecha.dia;
		 Edit5->Text=regA.fecha.mes;
		 Edit6->Text=regA.fecha.a�o;
		}

	}

}

//---------------------------------------------------------------------------

void __fastcall TForm2::Button7Click(TObject *Sender)
{
   pf->close();
   pIdx->close();
   delete(pf);
   delete(pIdx);
   Button7->Enabled=false;
   Button5->Enabled=false;
   Button6->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button6Click(TObject *Sender)
{
 RegIdxCod reg;
  RegAlumno regA;
  if (pIdx->is_open()) {
	  pIdx->read((char*)&reg,sizeof(reg));
	  if (!pIdx->eof()) {
		  pf->seekp(reg.pos,ios::beg);
		  pf->read((char *)&regA,sizeof (regA));
		  Edit1->Text=regA.cod;
		  Edit2->Text=regA.nom;
		  Edit3->Text=regA.dir;
		  //MaskEdit1->Text=IntToStr(regA.fecha.dia)+"/"+IntToStr(regA.fecha.mes)+"/"+IntToStr(regA.fecha.a�o); 	Edit4->Text=regA.fecha.dia
		  Edit4->Text=regA.fecha.dia;
		  Edit5->Text=regA.fecha.mes;
		  Edit6->Text=regA.fecha.a�o;
		  Button6->Enabled=true;
		  Button5->Enabled=true;
	  } else {
		 pIdx->close();
		 delete(pIdx);
		 pIdx=new fstream(nomIdxCod.c_str(),ios::in|ios::binary);
		 pIdx->seekp(0,ios::end);
		 Button6->Enabled=false;  //anulamos el avance adelante
		 Button5->Enabled=true;//habilitamos el retroceso
	  }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button5Click(TObject *Sender)
{
	 RegIdxCod reg;
  RegAlumno regA;
  Cardinal p;
  if (pIdx->is_open()) {
	p=pIdx->tellp();
	if (p<=sizeof(reg)){ //si est� en el primer registro del idx
	  Button5->Enabled=false;
	}else {
	  pIdx->seekp(-2*sizeof(reg),ios::cur);
	  pIdx->read((char*)&reg,sizeof(reg));
	  if (!pIdx->eof()) {
		  pf->seekp(reg.pos,ios::beg);
		  pf->read((char *)&regA,sizeof(regA));
		  Edit1->Text=regA.cod;
		  Edit2->Text=regA.nom;
		  Edit3->Text=regA.dir;
		 // MaskEdit1->Text=IntToStr(regA.fecha.dia)+"/"+IntToStr(regA.fecha.mes)+"/"+IntToStr(regA.fecha.a�o);

		  Edit4->Text=regA.fecha.dia;
		  Edit5->Text=regA.fecha.mes;
		  Edit6->Text=regA.fecha.a�o;
		  Button5->Enabled=true;
		  Button6->Enabled=true;
	  }
	}
  }
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button8Click(TObject *Sender)
{
    if (openTxtDlg->Execute(this->Handle))
	{
		// Setting the filename and encoding selected by the user
		String filename = openTxtDlg->FileName;

		int encIndex = openTxtDlg->EncodingIndex;

		TEncoding* enc = dynamic_cast<TEncoding*>
			(openTxtDlg->Encodings->Objects[encIndex]);

		// Checking if the file exists
		if (FileExists(filename))
		{
			// Display the contents in a memo based on the selected encoding.
			Memo1->Lines->LoadFromFile(filename, enc);
		}
		else
		{
			MessageDlg("File does not exist", mtError,
				TMsgDlgButtons() << mbOK, 0);
		}
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button9Click(TObject *Sender)
{
    if (saveTxtDlg->Execute(this->Handle))
	{
		// Setting the filename and encoding selected by the user
		String filename = saveTxtDlg->FileName;

		int encIndex = saveTxtDlg->EncodingIndex;

		TEncoding* enc = dynamic_cast<TEncoding*>
			(saveTxtDlg->Encodings->Objects[encIndex]);

		// Checking if the file exists
		if (FileExists(filename))
		{
//			MessageDlg("File already exists", mtError,
//				TMsgDlgButtons() << mbOK, 0);
			Memo1->Lines->SaveToFile(filename, enc);
		}
		else
		{
			// Saves to file based on the selected encoding.
			Memo1->Lines->SaveToFile(filename, enc);
		}

	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::porcodigo2Click(TObject *Sender)
{
	bool fin = false;
	Cardinal p, i, pm, z;
	if ( f.is_open()) {
		p = 0;
		while ( !fin ) {
			i = 0; pm = p;
			f.seekg(p); // ,ios::beg); // al inicio del archivo
			while ( !f.eof() ) { // buscar el menor
				if ( p == f.tellp() ) { // si es el primer registro
					f.read((char *)&reg,sizeof(reg));
					regM = reg;
					z = f.tellp();
				}else{
					f.read((char *)&reg,sizeof(reg));
					z = f.tellp();
				}
				if ( !f.eof() ) {
					i ++;
					if ( reg.cod < regM.cod ) {
						regM = reg;
						pm = f.tellp()-sizeof(reg);
					}
				}
			}
			fin = i <= 1;
			if ( !fin ) {
				//f.flush();
				f.close();
				f.open(nomIdxCod.c_str(),ios::in|ios::out|ios::b
			}
		}
	}
}
//---------------------------------------------------------------------------

