#include "MainForm.h"
#include <vector>
#include "Entity.h"
#include "ModelLoader.h"
#include <msclr\marshal_cppstd.h>
#include "BinaryLoader.h"

System::Void Model2BIN::MainForm::BrowseInput_Click(System::Object ^ sender, System::EventArgs ^ e) {
	OpenFileDialog openFileDialog1;

	// Set filter options and filter index.
	openFileDialog1.Filter = "Obj Files (.obj)|*.obj|All Files (*.*)|*.*";
	openFileDialog1.FilterIndex = 1;

	openFileDialog1.Multiselect = true;

	// Call the ShowDialog method to show the dialog box.
	System::Windows::Forms::DialogResult userClicked = openFileDialog1.ShowDialog();

	// Process input if the user clicked OK.
		// Open the selected file to read.
	if(userClicked == System::Windows::Forms::DialogResult::OK) {
		loadFileString = openFileDialog1.FileName;
		InputTextBox->Text = loadFileString;
		LoadButton->Enabled = true;
	}
	return System::Void();
}


System::Void Model2BIN::MainForm::LoadButton_Click(System::Object^  sender, System::EventArgs^  e) {
	System::String^ managed = loadFileString;
	std::string fileString = msclr::interop::marshal_as<std::string>(managed);
	EntityList = ModelLoader::readModel(fileString.c_str());
	return System::Void();
}

System::Void Model2BIN::MainForm::BrowseOutputButton_Click(System::Object^  sender, System::EventArgs^  e) {
	SaveFileDialog openFileDialog1;

	// Set filter options and filter index.
	openFileDialog1.Filter = "Bin Files (.bin)|*.bin|All Files (*.*)|*.*";
	openFileDialog1.FilterIndex = 1;

	// Call the ShowDialog method to show the dialog box.
	System::Windows::Forms::DialogResult userClicked = openFileDialog1.ShowDialog();

	// Process input if the user clicked OK.
	// Open the selected file to read.
	if (userClicked == System::Windows::Forms::DialogResult::OK) {
		saveFileString = openFileDialog1.FileName;
		OutputTextBox->Text = loadFileString;
		ExportButton->Enabled = true;
	}
	return System::Void();
}

System::Void Model2BIN::MainForm::ExportButton_Click(System::Object^  sender, System::EventArgs^  e) {
	std::vector<Entity*> *entities = static_cast<std::vector<Entity*>*>(EntityList);
	System::String^ managed = saveFileString;
	std::string fileString = msclr::interop::marshal_as<std::string>(managed);
//	for (Entity * ent : *entities) {
		
//	}
	BinaryLoader::createFile(fileString.c_str(), (*entities)[0]->VBOs);

	return System::Void();
}
