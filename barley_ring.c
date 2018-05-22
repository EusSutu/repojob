/***************************************************
 *                                                 *
 * Last attempt at a code to calcule lost barley   *
 * by A. Farmer                                    *
 * 18/05/18                                        *
 *                                                 *
 ***************************************************/

// Include any headers from the C standard library here
#include <stdio.h>
#include <stdlib.h>

// Define any constants that I need to use here
#define PI 3.14159

// This is where I should put my function prototypes
float area_of_circle(float radius); 
float area_of_rectangle(float l1,float l2);

// Now I start my code with main()
int main() {

    // In here I need to delare my variables
    int no_of_figures, i;
    int *fig_type;
    //lenght 1 represents inner radius of the ring, one of the rectangle lenghts or 0 for a disk 
    //lenght 2 represents outer radius of the ring, the other rectangle lenght or the disk radius
    float *lenght1,*lenght2,*area;
    float total_area,loss_in_kg,loss_in_GBP;

    // Next I need to get input from the user.
    // I'll do this by using a printf() to ask the user to input the radii.

    printf("Input the number of figures for calculations: ");
    scanf("%d", &no_of_figures);   //First getting the number of radii to be inputed (needed for memory allocation)

    lenght1 = (float *)malloc(no_of_figures*sizeof(float));  //Memory allocation for the inner radii
    lenght2 = (float *)malloc(no_of_figures*sizeof(float));  //Memory allocation for the outer radii
    fig_type  = (int *)malloc(no_of_figures*sizeof(int));    //Memory allocation for the outer radii

    printf("Write 0 for disk, 1 for ring and 2 for rectangle.\n");
    printf("Input the relevant lenghts.\n");
    for(i=0; i<no_of_figures; i++)
    {
	printf("What type of figure is it?");
	scanf("%d", fig_type+i);
 	if(fig_type[i]==1)
	{
            printf("Inner radius number %d: ",i+1);
            scanf("%f", lenght1+i);
            printf("Outer radius number %d: ",i+1);
            scanf("%f", lenght2+i);

	    if(lenght1[i]>lenght2[i])
	    {
	        printf("The inner radius is larger then the outer radius");
	        exit(1);
	    }
        }
	else if(fig_type[i]==0)
	{
	    printf("Radius number %d: ",i+1);
            scanf("%f", lenght2+i);
            lenght1[i] = 0;
        }
	else if(fig_type[i]==2)
	{
	    printf("The first lenght is: ");
	    scanf("%f", lenght1+i);
	    printf("The second lenght is: ");
	    scanf("%f", lenght2+i);
	}
	else
	{
	    printf("You have not entered 0, 1 or 2.");
	}
    }
    
    // Now I need to loop through the figures caluclating the area for each

    area = (float *)malloc(no_of_figures*sizeof(float));  //Memory allocation for the areas.

    for(i=0;i<no_of_figures;i++)
	{
	    if(fig_type[i] == 2)
	    {
		area[i] = area_of_rectangle(lenght1[i],lenght2[i]);
	    }
	    else
	    {
	        area[i] = area_of_circle(lenght2[i])-area_of_circle(lenght1[i]);
	    }
	}
    // Next I'll sum up all of the individual areas

    for(i=0;i<no_of_figures;i++)
	total_area+=area[i];

    /******************************************************************
     *                                                                *
     * Now I know the total area I can use the following information: *
     *                                                                *
     * One square meter of crop produces about 135 grams of barley    *
     *                                                                *
     * One kg of barley sells for about 10 pence                      *
     *                                                                *
     ******************************************************************/

    // Using the above I'll work out how much barley has been lost.
    loss_in_kg = total_area*0.135;

    // Using the loss in kg we find the value of barley lost in GBP.
    loss_in_GBP = loss_in_kg*0.1;

    // Finally I'll use a printf() to print this to the screen.
    printf("\nTotal area lossed in m^2 is:\t%f\n", total_area);
    printf("Total loss in kg is:\t\t%f\n", loss_in_kg);
    printf("Total loss in GBP is:\t\t%f\n", loss_in_GBP);

    return(0);
}

// I'll put my functions here:


float area_of_circle(float radius)
{
    //Function calculating area of a circle given radius.
    float area;
    area = PI * radius * radius;
    return area;
}

float area_of_rectangle(float lenght1,float lenght2)
{
    float area;
    area = lenght1 * lenght2;
    return area;
}
