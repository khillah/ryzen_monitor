/**
 * Ryzen SMU Userspace Sensor Monitor
 * Copyright (C) 2021-2022
 *    Florian Huehn <hattedsquirrel@gmail.com> (https://hattedsquirrel.net)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/

/**
 * This file contains the mapping of every known PM Table version
 **/

#include <pm_tables.h>

void pm_table_0x380904(pm_table *pmt, unsigned char* base_addr); //5900X: Zen3, 16 cores, version 4
void pm_table_0x380905(pm_table *pmt, unsigned char* base_addr); //5900X: Zen3, 16 cores, version 5
void pm_table_0x380804(pm_table *pmt, unsigned char* base_addr); //5600X: Zen3,  8 cores, version 4
void pm_table_0x380805(pm_table *pmt, unsigned char* base_addr); //5600X: Zen3,  8 cores, version 5
void pm_table_0x400005(pm_table *pmt, unsigned char* base_addr); //5700G: Zen3,  8 cores, GPU, version 5
void pm_table_0x240903(pm_table *pmt, unsigned char* base_addr); //3700X: Zen2,  8 cores, version 3
void pm_table_0x240803(pm_table *pmt, unsigned char* base_addr); //3950X: Zen2, 16 cores, version 3

void get_table(pm_table *pmt, unsigned char* base_addr, unsigned int version)
{
    switch(version)
    {
    case 0x380904:
        return pm_table_0x380904(pmt, base_addr);
    case 0x380905:
        return pm_table_0x380905(pmt, base_addr);
    case 0x380804:
        return pm_table_0x380804(pmt, base_addr);
    case 0x380805:
        return pm_table_0x380805(pmt, base_addr);
    case 0x400005:
        return pm_table_0x400005(pmt, base_addr);
    case 0x240903:
        return pm_table_0x240903(pmt, base_addr);
    case 0x240803:
        return pm_table_0x240803(pmt, base_addr);
    }
}
