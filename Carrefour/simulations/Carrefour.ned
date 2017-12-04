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
        int numerocasse = 30;
        double delay = 10.0; //Minimun delay for reach the nearest till, the delay grows linerly in proprtion 
							//to the distance (in our simulation the distance is rappresented by the position
							//of a specific till in the array)
        @display("bgb=747,274");
    submodules:
        casse[numerocasse]: Cassa {
            @display("p=555,69");
        }
        coda: Coda {
            @display("p=92,69");
        }
        decisore: Decisore {
            @display("p=328,185");
        }
    connections:
        for i=0..numerocassse {
            casse[i].in <-- coda.out;
            coda.out --> casse[i].in;
        }
}
