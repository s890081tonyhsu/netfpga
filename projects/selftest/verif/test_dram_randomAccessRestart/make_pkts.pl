#!/usr/local/bin/perl -w
# make_pkts.pl
#
#
#

use NF::PacketGen;
use NF::PacketLib;

use SimLib;

use reg_defines_selftest;

$delay = 0;
$batch = 0;
nf_set_environment( { PORT_MODE => 'PHYSICAL', MAX_PORTS => 4 } );

# use strict AFTER the $delay and $batch are declared
use strict;
use vars qw($delay $batch);

# Attempt to write a word
$delay = 5000;
nf_PCI_write32( $delay, $batch, DRAM_BASE_ADDR() + 0x00, 0x12345678 );
nf_PCI_write32( $delay, $batch, DRAM_BASE_ADDR() + 0x04, 0xaaaaaaaa );
nf_PCI_write32( $delay, $batch, DRAM_BASE_ADDR() + 0x08, 0xabcd9876 );
nf_PCI_write32( $delay, $batch, DRAM_BASE_ADDR() + 0x0c, 0xfeedf00d );

# Read the word back again
$delay = 0;
nf_PCI_read32( $delay, $batch, DRAM_BASE_ADDR() + 0x00, 0x12345678);
nf_PCI_read32( $delay, $batch, DRAM_BASE_ADDR() + 0x04, 0xaaaaaaaa);
nf_PCI_read32( $delay, $batch, DRAM_BASE_ADDR() + 0x08, 0xabcd9876);
nf_PCI_read32( $delay, $batch, DRAM_BASE_ADDR() + 0x0c, 0xfeedf00d);

# Attempt to start the self test (enabling only the random test)
nf_PCI_write32( $delay, $batch, DRAM_TEST_EN_REG(), 0x00000010 );
nf_PCI_write32( $delay, $batch, DRAM_TEST_CTRL_REG(), 0x00000001 );

# Verify that the test succeeded
#
# Check that only 1 test has completed
$delay = 50000;
nf_PCI_read32( $delay, $batch, DRAM_TEST_STATUS_REG(), 0x00000010 );

# Verify that there are 0 errors
$delay = 0;
nf_PCI_read32( $delay, $batch, DRAM_TEST_ERR_CNT_REG(), 0);


# *********** Finishing Up - need this in all scripts ! **********************
my $t = nf_write_sim_files();
print  "--- make_pkts.pl: Generated all configuration packets.\n";
printf "--- make_pkts.pl: Last packet enters system at approx %0d microseconds.\n",($t/1000);
if (nf_write_expected_files()) {
  die "Unable to write expected files\n";
}

nf_create_hardware_file('LITTLE_ENDIAN');
nf_write_hardware_file('LITTLE_ENDIAN');


