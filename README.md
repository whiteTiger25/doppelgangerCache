DoppelGanger Cache

In our Term Project for CSE614: Computer Architecture we have implemented this DoppelGanger Cache as described in [Doppelganger: A cache for approximate computing](https://www.researchgate.net/publication/282734767_Doppelganger_A_Cache_for_Approximate_Computing). This cache consumes significantly less power by reducing the on-chip silicon estate occupied by Last-Level-Cache. The cache lines are shared among different line addresses which map to the same key in the hash map. The authors propose modifying Instruction Set Architecture (ISA) to inlcude approximate Load and approximate Store in the ISA. They also propose we need to transfer the expected range for the data along with the newly introduced Assembly intructions. 

For this implementation purposes, instead of implementing new annotated ISA, we have annotated address range where the benchmarks will store it's approximable data. As each benchmark has different data range, we first capture this range for all benchmarks and later pass these information in the configuration carefully handcrafted for each benchmark. For fair comparison, we fix everything else(cache size and other specifications) across the configurations. Our choice was determined with our focus on getting compaative solution.

###### For more information regarding the DoppelgangerCache implementation and observations, check `CSCE614_TermReportFInal.pdf`