#include "Solution.h"
#pragma once
namespace LAB1 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form{
	public: MyForm(void){InitializeComponent();}
	protected: ~MyForm(){if (components){delete components;}}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  xx;
	private: System::Windows::Forms::TextBox^  yy;
	private: System::Windows::Forms::TextBox^  zz;



	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  aa;


	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  bb;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  lines;

	protected: 
	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void){
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->xx = (gcnew System::Windows::Forms::TextBox());
			this->yy = (gcnew System::Windows::Forms::TextBox());
			this->zz = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->aa = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->bb = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->lines = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(12, 449);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(117, 30);
			this->button1->TabIndex = 0;
			this->button1->Text = L"ОБЧИСЛИТИ";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			this->button1->MouseEnter += gcnew System::EventHandler(this, &MyForm::button1_MouseEnter);
			this->button1->MouseHover += gcnew System::EventHandler(this, &MyForm::button1_MouseHover);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(282, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Прога для обчислення рівняння";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// xx
			// 
			this->xx->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->xx->ImeMode = System::Windows::Forms::ImeMode::Alpha;
			this->xx->Location = System::Drawing::Point(35, 39);
			this->xx->MaxLength = 10;
			this->xx->Name = L"xx";
			this->xx->Size = System::Drawing::Size(194, 26);
			this->xx->TabIndex = 2;
			this->xx->Text = L"0";
			this->xx->TextChanged += gcnew System::EventHandler(this, &MyForm::xx_TextChanged);
			// 
			// yy
			// 
			this->yy->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->yy->ImeMode = System::Windows::Forms::ImeMode::Alpha;
			this->yy->Location = System::Drawing::Point(35, 71);
			this->yy->Name = L"yy";
			this->yy->Size = System::Drawing::Size(194, 26);
			this->yy->TabIndex = 3;
			this->yy->Text = L"0";
			this->yy->TextChanged += gcnew System::EventHandler(this, &MyForm::yy_TextChanged);
			// 
			// zz
			// 
			this->zz->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->zz->ImeMode = System::Windows::Forms::ImeMode::Alpha;
			this->zz->Location = System::Drawing::Point(35, 103);
			this->zz->Name = L"zz";
			this->zz->Size = System::Drawing::Size(194, 26);
			this->zz->TabIndex = 4;
			this->zz->Text = L"0";
			this->zz->TextChanged += gcnew System::EventHandler(this, &MyForm::zz_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(8, 39);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(21, 20);
			this->label2->TabIndex = 5;
			this->label2->Text = L"X";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(8, 71);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(21, 20);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Y";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(8, 103);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(20, 20);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Z";
			// 
			// aa
			// 
			this->aa->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->aa->ImeMode = System::Windows::Forms::ImeMode::Alpha;
			this->aa->Location = System::Drawing::Point(35, 206);
			this->aa->Name = L"aa";
			this->aa->Size = System::Drawing::Size(194, 26);
			this->aa->TabIndex = 4;
			this->aa->Text = L"-";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(8, 206);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(21, 20);
			this->label5->TabIndex = 5;
			this->label5->Text = L"A";
			// 
			// bb
			// 
			this->bb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->bb->ImeMode = System::Windows::Forms::ImeMode::Alpha;
			this->bb->Location = System::Drawing::Point(35, 238);
			this->bb->Name = L"bb";
			this->bb->Size = System::Drawing::Size(194, 26);
			this->bb->TabIndex = 4;
			this->bb->Text = L"-";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(8, 238);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(21, 20);
			this->label6->TabIndex = 5;
			this->label6->Text = L"B";
			// 
			// lines
			// 
			this->lines->AutoSize = true;
			this->lines->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->lines->Location = System::Drawing::Point(293, 39);
			this->lines->Name = L"lines";
			this->lines->Size = System::Drawing::Size(0, 20);
			this->lines->TabIndex = 6;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(467, 491);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->lines);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->bb);
			this->Controls->Add(this->aa);
			this->Controls->Add(this->zz);
			this->Controls->Add(this->yy);
			this->Controls->Add(this->xx);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"Обчислити";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_MouseHover(System::Object^  sender, System::EventArgs^  e) {}
	private: System::Void button1_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
				int locX = this->button1->Location.X;
				locX = (this->ClientSize.Width-100)  -locX + (((locX % 3)-1) * 50);
				
				int locY = this->button1->Location.Y;
				locY += (locX % 50) * (locX%3 - 1);
				if(locY < this->ClientSize.Height-200)locY+=100;
				if(locY > this->ClientSize.Height-50)locY-=100;
				this->button1->Location = System::Drawing::Point(locX, locY);
			 }
			 
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		double x, y, z;
		if(xx->Text->Length){
			x = System::Convert::ToDouble(xx->Text);
		}else{x = 0;}
		if(yy->Text->Length){
			y = System::Convert::ToDouble(yy->Text);
		}else{y = 0;}
		if(zz->Text->Length){
			z = System::Convert::ToDouble(zz->Text);
		}else{z = 0;}

		Solution solution;
		solution.Fn_b(x, y, z);
		solution.Fn_a(x, y, z);
		aa->Text = solution.geta()+"";
		if(aa->Text == "NaN")aa->Text = "-";
		bb->Text = solution.getb()+"";
		if(bb->Text == "NaN")bb->Text = "-";

		double 
			_y = 0.47 * 5.,
			_z = -1.32 * 0.5;
		lines->Text = L"";
		for(double _x = -1; _x<=1; _x+=0.2){
			solution.Fn_b(_x, _y, _z);
			solution.Fn_a(_x, _y, _z);
			lines->Text += 
				solution.round(_x, 1) + "   " + 
				solution.round(solution.geta(), 3) + "   " + 
				solution.round(solution.getb(), 3) + "   \n";
		}
	}
	private: System::Void xx_TextChanged(System::Object^  sender, System::EventArgs^  e) {button1_Click(sender, e);}
	private: System::Void yy_TextChanged(System::Object^  sender, System::EventArgs^  e) {button1_Click(sender, e);}
	private: System::Void zz_TextChanged(System::Object^  sender, System::EventArgs^  e) {button1_Click(sender, e);}

			 
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
};
}
