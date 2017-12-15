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

package carrefour;

//
// TODO auto-generated type
//
simple Decisore
{
     parameters:
         @signal[TotalTime](type = simtime_t);
         @signal[ActiveTill](type = int);
         @statistic[E_R](title="E[R]";source=TotalTime;record=mean,vector,min,max);
         @statistic[ActiveTillStat](title="Active Till";source=ActiveTill;record=mean,vector,min,max);
}