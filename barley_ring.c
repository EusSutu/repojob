/***************************************************
 *                                                 *
 * Second attempt at a code to calcule lost barley *
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

// Now I start my code with main()
int main() {

    // In here I need to delare my variables
    int no_of_rings, i;
    int *d_or_r;
    float *radii_inner,*radii_outer,*area;
    float total_area,loss_in_kg;

    // Next I need to get input from the user.
    // I'll do this by using a printf() to ask the user to input the radii.

    printf("Input the number of figures for calculations: ");
    scanf("%d", &no_of_rings);   //First getting the number of radii to be inputed (needed for memory allocation)

    radii_inner = (float *)malloc(no_of_rings*sizeof(float));  //Memory allocation for the inner radii
    radii_outer = (float *)malloc(no_of_rings*sizeof(float));  //Memory allocation for the outer radii
    d_or_r  = (int *)malloc(no_of_rings*sizeof(int));  //Memory allocation for the outer radii

    printf("Write 0 for disc and 1 for ring.\nWrite the radii values:\n");
    for(i=0; i<no_of_rings; i++)
    {
	printf("Is it disc or ring?");
	scanf("%d", d_or_r+i);
 	if(d_or_r[i]==1)
	{
            printf("Inner radius number %d: ",i+1);
            scanf("%f", radii_inner+i);
            printf("Outer radius number %d: ",i+1);
            scanf("%f", radii_outer+i);

	    if(radii_outer[i]<radii_inner[i])
	    {
	        printf("The inner radius is larger then the outer radius");
	        exit(1);
	    }
        }
	else if(d_or_r[i]==0)
	{
	    printf("Radius number %d: ",i+1);
            scanf("%f", radii_outer+i);
            radii_inner[i] = 0;
        }
	else
	{
	    printf("You have not entered 0 or 1.");
	}
    }
    
    // Now I need to loop through the radii caluclating the area for each

    area = (float *)malloc(no_of_rings*sizeof(float));  //Memory allocation for the areas.

    for(i=0;i<no_of_rings;i++)
	area[i] = area_of_circle(radii_outer[i])-area_of_circle(radii_inner[i]);

    // Next I'll sum up all of the individual areas

    for(i=0;i<no_of_rings;i++)
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

    // Finally I'll use a printf() to print this to the screen.
    printf("\nTotal area lossed in m^2 is:\t%f\n", total_area);
    printf("Total loss in kg is:\t\t%f\n", loss_in_kg);

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
