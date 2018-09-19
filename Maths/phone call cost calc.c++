struct phoneCall
{
    int type;
    int number_of_minutes;
    int total_cost;
    int cost_per_minute;
    int numberOfHours;
    int totalNumberInMinutes;
    int a = 0;
    int b = 1;
};
int main()
{
 phoneCall myCallToGrandmaOnSunday;
 /* choose the input of the time; if in minutes insert 0 else 1!!!*/
 cout<<"If total time is in minutes type 0 else type 1!"<<endl;
 cout<<""<<endl;
 cout<<" choose the time type "<<endl;
 cin>>myCallToGrandmaOnSunday.type;
 myCallToGrandmaOnSunday.cost_per_minute = 10;
 myCallToGrandmaOnSunday.a = 0;
 myCallToGrandmaOnSunday.b = 1;
  if ( myCallToGrandmaOnSunday.type == myCallToGrandmaOnSunday.a) {
 cout<<"input total time of calls in minutes "<<endl;
 cin>>myCallToGrandmaOnSunday.number_of_minutes;

 cout <<"cost per minute is = "<<myCallToGrandmaOnSunday.cost_per_minute<<" cent"<<endl;
 myCallToGrandmaOnSunday.total_cost = myCallToGrandmaOnSunday.cost_per_minute * myCallToGrandmaOnSunday.number_of_minutes;

 cout <<"-----------------------------------------------------------"<<endl;

 cout<<"the total cost of call = "<<myCallToGrandmaOnSunday.total_cost<<" cents"<<endl;
 }
 else if (myCallToGrandmaOnSunday.type==myCallToGrandmaOnSunday.b)
 {
     cout<<"input total time of calls in hours "<<endl;
 cin>>myCallToGrandmaOnSunday.numberOfHours;
 cout<<"input number of total time of calls in minutes "<<endl;
 cin>>myCallToGrandmaOnSunday.number_of_minutes;
 myCallToGrandmaOnSunday.totalNumberInMinutes = 60 * myCallToGrandmaOnSunday.numberOfHours + myCallToGrandmaOnSunday.number_of_minutes;

 cout <<"cost per minute is = "<<myCallToGrandmaOnSunday.cost_per_minute<<" cent"<<endl;
 myCallToGrandmaOnSunday.total_cost = myCallToGrandmaOnSunday.cost_per_minute * myCallToGrandmaOnSunday.totalNumberInMinutes;
 cout <<"-----------------------------------------------------------"<<endl;
 cout <<"total number of minutes = "<< myCallToGrandmaOnSunday.totalNumberInMinutes <<" minutes"<<endl;
 cout <<"-----------------------------------------------------------"<<endl;

 cout<<"the total cost of call = "<<myCallToGrandmaOnSunday.total_cost<<" cents"<<endl;
 }
    else (myCallToGrandmaOnSunday.type >=2 || myCallToGrandmaOnSunday.type <=-1);
{

           cout <<" Not accepted!!!"<<endl;
           cout <<" "<<endl;
           cout <<" input only 0 or 1"<<endl;
}

 return 0;
}
