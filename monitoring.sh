# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    monitoring.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 16:26:17 by rmei              #+#    #+#              #
#    Updated: 2024/06/19 16:28:53 by rmei             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash
arx=$(uname -srvmo)
pcpu=$(grep "physical id" /proc/cpuinfo | wc -l) 
vcpu=$(grep "^processor" /proc/cpuinfo | wc -l)
fram=$(free -m | awk '$1 == "Mem:" {print $2}')
uram=$(free -m | awk '$1 == "Mem:" {print $3}')
pram=$(free | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')
fdisk=$(df -BG | grep '^/dev/' | grep -v '/boot$' | awk '{ft += $2} END {print ft}')
udisk=$(df -BM | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} END {print ut}')
pdisk=$(df -BM | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} {ft+= $2} END {printf("%.2f"), ut/>
cpul=$(top -bn1 | grep '^%Cpu' | cut -c 9- | xargs | awk '{printf("%.2f%%"), $1 + $3}')
lb=$(who -b | awk '{print $3 " " $4}')
lvmu=$(lsblk | grep "lvm" | wc -l)
ctcp=$(ss -Ht state established | wc -l)
ulog=$(users | wc -w)
ip=$(hostname -I)
mac=$(ip link show | grep "ether" | awk '{print $2}')
cmds=$(journalctl _COMM=sudo | grep COMMAND | wc -l)
wall "  #OS Architecture: $arx
        #Physical CPU: $pcpu
        #Virtual CPU: $vcpu
        #Memory Usage: $uram/${fram}MB ($pram%)
        #Disk Usage: $udisk/${fdisk}Gb ($pdisk%)
        #CPU load: $cpul
        #Last Boot: $lb
        #LVM: $(if [ $lvmu -eq 0 ]; then echo inactive; else echo active; fi)
        #TCP Connections: $ctcp ESTABLISHED
        #Active Users: $ulog
        #Network: IP $ip ($mac)
        #Sudo: $cmds commands"
