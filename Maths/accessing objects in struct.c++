struct Car
{
intmodel_year;
doublemiles_per_gallon;

};

struct College
{
	intyearFounded;
	intstudentsPopulation;
	doubleannualTuition;
};

struct Computer
{
	intyearModel;
	intwidthsize;
	intheightsize;
	intnumber_of_computer;

};

int_tmain(intargc, _TCHAR* argv[])
{
	Car Mercedeze;
	Mercedeze.model_year = 2015;
	Mercedeze.miles_per_gallon = 5000.00;

	cout<<"the model year is  "<<Mercedeze.model_year<<endl;
	cout<<" the distance should be  "<<Mercedeze.miles_per_gallon<<"miles per gallon"<<endl;
	cout<<" --------------------------------------------------------------------------------------"<<endl;

	College OBHS;
	OBHS.yearFounded = 1891;
	OBHS.studentsPopulation = 5000;
	OBHS.annualTuition = 5000.00;

	cout<<" the year founded is "<<OBHS.yearFounded<<endl;
	cout<<" the number of population is "<<OBHS.studentsPopulation<<"students"<<endl;
	cout<<" the annual tuition fee is "<<OBHS.annualTuition<<" Dollars "<<endl;
	cout<<" --------------------------------------------------------------------------------------"<<endl;

	Computer my_Computer_device;
	my_Computer_device.yearModel = 2014;
	my_Computer_device.widthsize = 21;
	my_Computer_device.heightsize = 18;
	my_Computer_device.number_of_computer = 5;

	cout<<"the year model of my computer is "<<my_Computer_device.yearModel<<endl;
	cout<<"the height of my computer should be "<<my_Computer_device.heightsize<<"inches"<<endl;
	cout<<"the width of my computer should be "<<my_Computer_device.widthsize<<"inches"<<endl;
	cout<<"the number of computer needed is "<<my_Computer_device.number_of_computer<<"pieces"<<endl;
	return 0;
}

