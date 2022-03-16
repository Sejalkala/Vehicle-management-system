#include<stdio.h>
#include<string.h>

struct Vehicle
{
  char registration_no[100];
  char vehicle_type[100];
  char maker[200];
  int year_of_manufacture;
  char engine_no[100];
  unsigned int vehicle_price;
  int owners_ID;
};

struct Owner
{
    int owners_ID;               
    char owner_name[300];
    char father_name[300];
    char address[1000];
    int date_of_purchase[5];
    int month_of_purchase[5];
    int year_of_purchase[5];
    double purchase_amount[5];
    struct Vehicle Total_vehicles[5];
    int no_of_vehicles;
};
struct Owner Data[20000];

void swap(struct Vehicle* s1, struct Vehicle* s2)
{
    struct Vehicle temp  = *s1;
    *s1 = *s2;
    *s2 = temp;
}

int n_owner(int count)
{
	int i;
    struct Owner own;
    printf("Enter ID of new owner : ");
    scanf("%d",&own.owners_ID);
    for(i=0;i<count;i++){
        if(Data[i].owners_ID==own.owners_ID){
            printf("\n Owner with ID you entered already exists");
            return 0;
        }
    }
    printf("Owner's name : ");
    scanf("%s",own.owner_name);
    printf("Father's name : ");
    scanf("%s",own.father_name);
    printf("Address : ");
    scanf("%s",own.address);
    own.no_of_vehicles=0;
    Data[count]=own;
    printf("\n Added the owner successfully");
    return 1;
}

int n_vehicle()
{
    int id,i;
    printf("Enter ID of owner of new vehicle :");
    scanf("%d",&id);
    for(i=0;i<2000;i++)
    {
        if(Data[i].owners_ID==id){
            if(Data[i].no_of_vehicles==5){
                printf("\n owner has alrady 5 vehicles");
                return 0;
            }
            else{
                struct Vehicle v;
                printf("Vehicle type : ");
                scanf("%s",v.vehicle_type);
                printf("Vehicle maker : ");
                scanf("%s",v.maker);
                printf("Year of manufacture : ");
                scanf("%d",&v.year_of_manufacture);
                printf("Engine no : ");
                scanf("%s",v.engine_no);
                printf("Registration no : ");
                scanf("%s",v.registration_no);
                printf("Vehicle price : ");
                scanf("%d",&v.vehicle_price);
                v.owners_ID=id;
                printf("Date of purchase : ");
                scanf("%d",&Data[i].date_of_purchase[Data[i].no_of_vehicles]);
                printf("Month of purchase : ");
                scanf("%d",&Data[i].month_of_purchase[Data[i].no_of_vehicles]);
                printf("Year of purchase : ");
                scanf("%d",&Data[i].year_of_purchase[Data[i].no_of_vehicles]);
                Data[i].purchase_amount[Data[i].no_of_vehicles]=v.vehicle_price;
                Data[i].Total_vehicles[Data[i].no_of_vehicles]=v;
                Data[i].no_of_vehicles++;
                printf("\n Added the Vehicle successfully");
                return 1;   
            }
        }
    }
    printf("\n Owner with ID you entered does not exists");
    return 0;
}

void del_byId(int* count)
{
    int owner,i,j;
    printf("Owner's ID :");
    scanf("%d",&owner);
    for(i=0;i<*count;i++)
    {
        if(Data[i].owners_ID==owner)
        {
            char vehicleID[15];
            printf("Registration no of Vehicle : ");
            scanf("%s",vehicleID);
            
            for(j=0;j<Data[i].no_of_vehicles;j++)
            {
                if(strcmp(Data[i].Total_vehicles[j].registration_no,vehicleID)==0)
                {
                    while(j<Data[i].no_of_vehicles-1)
                    {
                        Data[i].Total_vehicles[j]=Data[i].Total_vehicles[j+1];
                        j++;
                    }
                    printf("Deleted the vehicle successfully\n");
                    j++;
                }
            }
            Data[i].no_of_vehicles--;
            if(Data[i].no_of_vehicles==0)

            {
                while(i<*count-1)
                {
                    Data[i]=Data[i+1];
                    i++;
                    *count=*count-1;
                }
                i++;
                printf("\n Entry of owner has been deleted");
            }
        }
    }
    return;
}

void list_ascend(int count)
{
    int id,i,j,k,l;
    printf("Owner's ID : ");
    scanf("%d",&id);
    for(i=0;i<count;i++)
    {
        if(Data[i].owners_ID==id)
        {
            for(j=0;j<Data[i].no_of_vehicles-1;j++)
            {
                for(k=0;k<Data[i].no_of_vehicles-1-j;k++)
                {
                    if(Data[i].Total_vehicles[k].year_of_manufacture >Data[i].Total_vehicles[k+1].year_of_manufacture)
                    {
                        swap(&Data[i].Total_vehicles[k],&Data[i].Total_vehicles[k+1]);
                    }
                }
            }
        }
    }
    printf("\n The owner with ID %d has following cars",id);
    for(l=0;l<Data[i].no_of_vehicles;l++)
    {
        printf("\n Vehicle with Reg no %s and year of manufacture %d",Data[i].Total_vehicles[l].registration_no,Data[i].Total_vehicles[l].year_of_manufacture);
    }
}

void del_before_1990(int *count)
{
	int i,j;
    for(i=0;i<*count;i++)
    {
        for(j=0;j<Data[i].no_of_vehicles;j++)
        {
            if(Data[i].Total_vehicles[j].year_of_manufacture<1990)
            {
                int b=j;
                while(b<Data[i].no_of_vehicles-1)
                {
                    Data[i].Total_vehicles[j]=Data[i].Total_vehicles[j+1];
                    b++;
                }
                Data[i].no_of_vehicles--;
                printf("Vehicle with registration number %s of owner %d with manufacture year %d has been deleted",Data[i].Total_vehicles[b].registration_no,Data[i].owners_ID,Data[i].Total_vehicles[b].year_of_manufacture);
            }
        }
        if(Data[i].no_of_vehicles==0)
        {
            int a=i;
            while(a<*count-1)
            {
                Data[a]=Data[a+1];
                a++;
            }
            *count=*count-1;
            printf("Owner with ID %d has been deleted\n",Data[i].owners_ID);
        }
    }
}
void max_secondmax_owner(int count)
{
    int max=Data[0].no_of_vehicles;
    int maxID=Data[0].owners_ID;
    int second_max=-1;
    int second_maxID;
    int i,j;
    for(i=1;i<count;i++)
    {
        if(Data[i].no_of_vehicles>max)
        {
            max=Data[i].no_of_vehicles;
            maxID=Data[i].owners_ID;
        }
    }
    for(j=0;j<count;j++)
    {
        if(Data[j].no_of_vehicles>second_max && Data[j].owners_ID!=maxID)
        {
            second_max=Data[j].no_of_vehicles;
            second_maxID=Data[j].owners_ID;
        }
    }
    printf("\n Owner with ID %d has maximum vehicles (%d)",maxID,max);
    printf("\n Owner with ID %d has second maximum vehicles (%d)",second_maxID,second_max);
    return ;
    
}

void morethan2_owner(int count)
{
	int i,j,k;
    printf("\n IDs of all the owners who purchased more than 1-wheeler, 2-wheeler vehicles in the same year");
    for(i=0;i<count;i++)
    {
        int count=0;
        for(j=0;j<Data[i].no_of_vehicles; j++){
            if(strcmp(Data[i].Total_vehicles[j].vehicle_type,"2-wheeler")==0)
            {
                int year=Data[i].Total_vehicles[j].year_of_manufacture;
                for(k=j+1;k<Data[i].no_of_vehicles;k++)
                {
                    if(Data[i].Total_vehicles[k].year_of_manufacture==year && Data[i].Total_vehicles[k].vehicle_type=="2-wheeler")
                    {
                        count++;
                    }
                }
            } 
        }
        if(count>1)
        {
            printf("\n %d",Data[i].owners_ID);
        }
    }
    return;
}

void costliest_vahicle(int count)
{
    int id,i,j;
    printf("\n Owner's ID: ");
    scanf("%d",&id);
    int retval=0;
    for(i=0;i<count;i++)
    {
        if(Data[i].owners_ID==id)
        {
            int expensive=0;
            if(Data[i].no_of_vehicles==0)
            {
                printf("\n Owner does not have any vehicle");
                return;
            }
            else
            {   
                for(j=0;j<Data[i].no_of_vehicles;j++)
                {
                    if(Data[i].Total_vehicles[j].vehicle_price>expensive)
                    {
                        expensive=Data[i].Total_vehicles[j].vehicle_price;
                    }
                }
                printf("\n Vehicle with highest price owned by given owner is %d",expensive);
                retval=1;
            }
        }
    }
    if(retval==0)
    {
        printf("\n No owner with given ID is found");
    }
    return;
}

void brand_owner(int count)
{
    char brand[20];
    printf("Name of Brand : ");
    scanf("%s",brand);
    int retval=0,i,j;
    
    for(i=0;i<count;i++)
    {
        int count=0;
        for(j=0;j<Data[i].no_of_vehicles;j++)
        {
            if(strcmp(Data[i].Total_vehicles[j].maker,brand)==0)
            {
                count++;
            }
        }
        if(count>1)
        {
            printf("\n %d",Data[i].owners_ID);
            retval=1;
        }
    }
    if(retval==0)
    {
        printf("\n No Such Owner exist");
    }
    return;
}

void list_ownerpurchased3wheeler(int count)
{
    int curr_y,retval=0,i,j;
    printf("\n Year :");
    scanf("%d",&curr_y);
    retval=0,i,j;
    for(i=0; i<count; i++)
    {
        for(j=0; j<Data[i].no_of_vehicles; j++)
        {
            if(Data[i].Total_vehicles[j].year_of_manufacture==curr_y && strcmp(Data[i].Total_vehicles[j].vehicle_type,"3-wheeler")==0)
            {
                printf("\n %d",Data[i].owners_ID);
                retval=1;
                break;
            }
        }
    }
    if(retval==0){
        printf("\n No such Owner exists");
    }
    return;
}


int main()
{
    int count=0;
	int option;
	printf("\n choose option no to perform required action");
	printf("\n 0)Exit the program");
	printf("\n 1)Add a new Owner");
	printf("\n 2)Add a new vehicle to the owner");
	printf("\n 3)Delte a vehicle by ID");
	printf("\n 4)List all the cars of particular owner in ascending order of year of manufacture");
	printf("\n 5)Delete all cars from the structure above that have a manufacturing year before 1990");
	printf("\n 6)Find out owner with maximum and second maximum number of vehicles");
	printf("\n 7)List all the owners who purchased more than 1, 2-wheeler vehicles in the same year");
	printf("\n 8)Find out the price of the costliest vehicle owned by the owner entered by the user");
	printf("\n 9)Find the owners who own more than one vehicle of the brand chosen by the user");
	printf("\n 10)List the owners who purchased 3-wheeler in the year provided by the user");
	do
	{
	    printf("\n\nEnter option : ");
	    scanf("%d",&option);
	    if(option==1)
	    {
	        if(n_owner(count))
    	            count++;
	    }
	    else if(option==2)
	    {
	        n_vehicle();
	    }
    	else if(option==3)
    	{
    	    del_byId(&count);
    	}
    	else if(option==4)
    	{
    	    list_ascend(count);
    	}
    	else if(option==5)
    	{
    	     del_before_1990(&count);
    	}
    	else if(option==6)
    	{
    	        max_secondmax_owner(count);
    	}
    	else if(option==7)
    	{
    	        morethan2_owner(count);
    	}
    	else if(option==8)
    	{
    	        costliest_vahicle(count);
    	}
    	else if(option==9)
    	{
    	        brand_owner(count);
    	}
    	else if(option==10)
    	{
    	        list_ownerpurchased3wheeler(count);
    	}
    	else
    	{
    	       printf("\n Enter Correct Choice");
    	}
	}while(option!=0);
    return 0;
}

