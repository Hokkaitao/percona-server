################################################################################
# inc/vcol_unsupported_storage_engines.inc                                     #
#                                                                              #
# Purpose:                                                                     #
#  Ensure that defining a virtual column for an unsupported table type         #
#  results in a graceful error.                                                #
#                                                                              #
#------------------------------------------------------------------------------#
# Original Author: Andrey Zhakov                                               #
# Original Date: 2008-09-02                                                    #
# Change Author:                                                               #
# Change Date:                                                                 #
# Change:                                                                      #
################################################################################

--error ER_UNSUPPORTED_ACTION_ON_VIRTUAL_COLUMN
create table t1 (a int, b virtual int as (a+1));
create table t1 (a int);
--error ER_UNSUPPORTED_ACTION_ON_VIRTUAL_COLUMN
alter table t1 add column b virtual int as (a+1);
drop table t1;