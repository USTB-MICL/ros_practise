#!/usr/bin/env python
import numpy as np
import os
import six.moves.urllib as urllib
import sys
import tarfile
import tensorflow as tf
import zipfile

from collections import defaultdict
from io import StringIO
from matplotlib import pyploy as plt
from PIL import Image

if tf.__version__ < '1.4.0':
    raise ImportError('Please upgrade your tensorflow'
                      'installation to v1.4.* or later!')


# can remove
sys.path.append("..")

from utils import label_map_util
from utils import visualization_utils as vis_util
