import infiniband.*;
package infiniband.simulations.switch8;

network switch8
{
    submodules:
        H[8]: HCA {
            parameters:
                @display("i=device/server2");
        }

        sw: Switch {
            parameters:
                numSwitchPorts = 8;
                @display("p=182,58");
            gates:
                port[8];
        }
    
    connections:
        for k = 0..7 
        {
            H[k].port <--> IB4XEDRWire <--> sw.port[k];
        }
}