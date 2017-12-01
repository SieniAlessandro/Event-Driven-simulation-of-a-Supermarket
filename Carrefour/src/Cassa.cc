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

#include "Cassa.h"

Define_Module(Cassa);

void Cassa::initialize()
{
    //Obtaing the reference to the module Decisore,to use its own methods
    this->decisore = check_and_cast<Decisore *> (getModuleByPath("Decisore"));
}

void Cassa::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
}
