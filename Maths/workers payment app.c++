struct worker
{
    int number_of_hours;
    int days;
    int remaining_days;
    int total;
    int days_needed;
    int partial_days;
};
int main()
{
    worker clients;

    cout << "number of hours " << endl;
    cin>>clients.number_of_hours;

    clients.days = clients.number_of_hours/8;
    clients.remaining_days = clients.number_of_hours%8;

    clients.days_needed = 8-clients.remaining_days;
    clients.partial_days = 40*clients.remaining_days;
    clients.total = 200*clients.days + clients.partial_days;
    cout<<"the total eight-hour working days: "<< clients.days <<" days"<<endl;
    cout<<"--------------------------------------------------------------"<<endl;
    cout<<"the remaining days needed: "<<clients.days_needed<<" days"<<endl;
    cout<<"--------------------------------------------------------------"<<endl;
    cout<<"the cost of the partial days: "<<clients.partial_days<<" dollars" <<endl;
    cout<<"--------------------------------------------------------------"<<endl;
    cout<<"the total cost of your work is "<<clients.total<<" dollars"<<endl;
    cout<<"================================================================="<<endl;
    cout<<"=================================================================="<<endl;


return 0;
}
