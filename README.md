VideoProcessViewer
==================

Compilation
-----------

Requires [SFML](https://github.com/SFML/SFML/) (tested with 2.4).
The repository contains [ImGui](https://github.com/ocornut/imgui), [ImGui-SFML](https://github.com/eliasdaler/imgui-sfml) and [iio](https://github.com/mnhrdt/iio).

```sh
mkdir build
cd build
cmake ..
make
```

Move build/viewer wherever you want or setup an alias.

Concepts
--------

**Sequence**: ordered collection of images.

**Window**: zone to display one or more sequences. If multiple sequences are attached to a window, 'space' and 'backspace' are use to cycle between them.

**View**: indicate the portion of the image to display. Contains a center position and a zoom factor.

**Player**: indicate which image in the sequence should be displayed. Contains a few other parameters (check out the player GUI to see what it can do).

**Colormap**: transformation of the pixels of an image. Contains scale/bias parameters (output=scale\*pixel+bias) and a shader (to display optical flow, greyscale or color images).

By combining these concepts, VideoProcessViewer becomes a very convenient image/video viewer.

For example, if two sequences share the same view, the same window and the same player, you can visualize the differences between two videos by flipping between them (using 'space').

If you want to see both of them at the same time, attach the two sequences to different windows, and VideoProcessViewer will show them side by side, still keeping the view and timing synchronized.

If the images of multiple sequences don't have the same intensities (one between 0-255 and one between 0-1 for example), you can use two Colormap objects. They automatically adjust their parameters to normalize the image and fit its number of channels.

Command line arguments
----------------------

Sequences can be specified either by escaped globbing (e.g. *directory/my_images\_\\\*.png*) or by a single image (in this case, it will be a one image sequence).

**nw**, **nv**, **np**, **nc **are used as arguments to respectively create a new window, view, player or colormap for the following sequences.

Display to sequences side by side:

```bash
viewer input_\*.png nw output_\*.png
```

Display all the images of the directory in the same window ('space' can be used to cycle through them):

```bash
viewer \*.jpg
```

Remarks
-------

Despite its name, VideoProcessViewer cannot open video files. Use ffmpeg to split a video into individual frames. This may change in the future.

In order to be reactive during video playback, the frames are loaded in advance by a thread and put to cache. Currently, the cache has no memory limit, so do not load large sequences (or small sequences of large images) if your computer cannot handle it. This may change in the future.
Also, a consequence of this cache is that if the image is changed on disk, VideoProcessViewer will display its old content. This will definitely change in the future (with an option to keep the content, this can still be useful).

Similarly to the previous remark, the globbing expansion is only done at startup. If new images are saved to disk, VideoProcessViewer won't see them (except if you update the globbing in the sequence GUI). This will change in the future.

VideoProcessViewer is not a great software name. This may change in the future.


Related projects
----------------

[pvflip](https://github.com/gfacciol/pvflip) (VideoProcessViewer is heavily inspired by pvflip)

[G'MIC](https://github.com/dtschump/gmic)

