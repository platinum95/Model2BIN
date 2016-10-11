#pragma once
#include <string>

namespace Model2BIN {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  InputTextBox;
	private: System::Windows::Forms::TextBox^  OutputTextBox;
	protected:

	protected:

	private: System::Windows::Forms::Button^  BrowseInput;
	private: System::Windows::Forms::Button^  LoadButton;
	private: System::Windows::Forms::Button^  BrowseOutputButton;
	private: System::Windows::Forms::Button^  ExportButton;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->InputTextBox = (gcnew System::Windows::Forms::TextBox());
			this->OutputTextBox = (gcnew System::Windows::Forms::TextBox());
			this->BrowseInput = (gcnew System::Windows::Forms::Button());
			this->LoadButton = (gcnew System::Windows::Forms::Button());
			this->BrowseOutputButton = (gcnew System::Windows::Forms::Button());
			this->ExportButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// InputTextBox
			// 
			this->InputTextBox->Location = System::Drawing::Point(28, 26);
			this->InputTextBox->Name = L"InputTextBox";
			this->InputTextBox->Size = System::Drawing::Size(289, 20);
			this->InputTextBox->TabIndex = 0;
			// 
			// OutputTextBox
			// 
			this->OutputTextBox->Location = System::Drawing::Point(374, 26);
			this->OutputTextBox->Name = L"OutputTextBox";
			this->OutputTextBox->Size = System::Drawing::Size(289, 20);
			this->OutputTextBox->TabIndex = 1;
			// 
			// BrowseInput
			// 
			this->BrowseInput->Location = System::Drawing::Point(28, 68);
			this->BrowseInput->Name = L"BrowseInput";
			this->BrowseInput->Size = System::Drawing::Size(75, 23);
			this->BrowseInput->TabIndex = 2;
			this->BrowseInput->Text = L"Browse";
			this->BrowseInput->UseVisualStyleBackColor = true;
			this->BrowseInput->Click += gcnew System::EventHandler(this, &MainForm::BrowseInput_Click);
			// 
			// LoadButton
			// 
			this->LoadButton->Location = System::Drawing::Point(242, 68);
			this->LoadButton->Name = L"LoadButton";
			this->LoadButton->Size = System::Drawing::Size(75, 23);
			this->LoadButton->TabIndex = 3;
			this->LoadButton->Text = L"Load";
			this->LoadButton->UseVisualStyleBackColor = true;
			this->LoadButton->Click += gcnew System::EventHandler(this, &MainForm::LoadButton_Click);
			// 
			// BrowseOutputButton
			// 
			this->BrowseOutputButton->Location = System::Drawing::Point(374, 68);
			this->BrowseOutputButton->Name = L"BrowseOutputButton";
			this->BrowseOutputButton->Size = System::Drawing::Size(75, 23);
			this->BrowseOutputButton->TabIndex = 4;
			this->BrowseOutputButton->Text = L"Browse";
			this->BrowseOutputButton->UseVisualStyleBackColor = true;
			this->BrowseOutputButton->Click += gcnew System::EventHandler(this, &MainForm::BrowseOutputButton_Click);
			// 
			// ExportButton
			// 
			this->ExportButton->Location = System::Drawing::Point(588, 68);
			this->ExportButton->Name = L"ExportButton";
			this->ExportButton->Size = System::Drawing::Size(75, 23);
			this->ExportButton->TabIndex = 5;
			this->ExportButton->Text = L"Export";
			this->ExportButton->UseVisualStyleBackColor = true;
			this->ExportButton->Click += gcnew System::EventHandler(this, &MainForm::ExportButton_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(718, 295);
			this->Controls->Add(this->ExportButton);
			this->Controls->Add(this->BrowseOutputButton);
			this->Controls->Add(this->LoadButton);
			this->Controls->Add(this->BrowseInput);
			this->Controls->Add(this->OutputTextBox);
			this->Controls->Add(this->InputTextBox);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Void BrowseInput_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void LoadButton_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void BrowseOutputButton_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void ExportButton_Click(System::Object^  sender, System::EventArgs^  e);
		System::String^ loadFileString, ^saveFileString;
		void* EntityList;

};
}
