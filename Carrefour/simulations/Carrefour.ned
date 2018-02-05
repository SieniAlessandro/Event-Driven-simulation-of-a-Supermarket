//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package carrefour.simulations;
import carrefour.*;

//
// TODO auto-generated type
//
network Carrefour
{
    parameters:
        int numeroCasse;
        double delay; //Minimun delay for reach the nearest till, the delay grows linerly in proprtion 
							//to the distance (in our simulation the distance is rappresented by the position
							//of a specific till in the array)
        double lambda;
        double mu;
        double varianceLogNormal;
        double meanLogNormal;
        int tipoSimulazione;
        int ServiceType; 	//This variable is used to indicate the distribution of the service demand
        					//0 : exponential
        					//1 : lognormal
    submodules:
        casse[numeroCasse]: Cassa {
            @display("p=88,44");
        }
        coda: Coda {
            casse = numeroCasse;
            @display("p=293,44");
        }
        decisore: Decisore {
            @display("p=402,125");
        }
    connections:
        for i=0..numeroCasse-1 {
            //casse[i].in <-- coda.out;
            coda.out[i] --> casse[i].in;
            casse[i].out --> coda.in[i];
        }
}
