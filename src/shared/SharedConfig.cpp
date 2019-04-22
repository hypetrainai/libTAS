#include "SharedConfig.h"

std::ostream& operator<<(std::ostream& os, const SharedConfig& sc)
{
    return os << "SharedConfig:" << std::endl
      << "  running: " << sc.running << std::endl
      << "  speed_divisor: " << sc.speed_divisor << std::endl
      << "  fastforward: " << sc.fastforward << std::endl
      << "  fastforward_mode: " << sc.fastforward_mode << std::endl
      << "  recording: " << sc.recording << std::endl
      << "  movie_framecount: " << sc.movie_framecount << std::endl
      << "  initial_framecount: " << sc.initial_framecount << std::endl
      << "  logging_status: " << sc.logging_status << std::endl
      << "  av_dumping: " << sc.av_dumping << std::endl
      << "  framerate_num: " << sc.framerate_num << std::endl
      << "  framerate_den: " << sc.framerate_den << std::endl
      << "  keyboard_support: " << sc.keyboard_support << std::endl
      << "  mouse_support: " << sc.mouse_support << std::endl
      << "  nb_controllers: " << sc.nb_controllers << std::endl
      << "  osd: " << sc.osd << std::endl
      << "  osd_encode: " << sc.osd_encode << std::endl
      << "  prevent_savefiles: " << sc.prevent_savefiles << std::endl
      << "  write_savefiles_on_exit: " << sc.write_savefiles_on_exit << std::endl
      << "  audio_bitdepth: " << sc.audio_bitdepth << std::endl
      << "  audio_channels: " << sc.audio_channels << std::endl
      << "  audio_frequency: " << sc.audio_frequency << std::endl
      << "  audio_mute: " << sc.audio_mute << std::endl
      << "  video_codec: " << sc.video_codec << std::endl
      << "  video_bitrate: " << sc.video_bitrate << std::endl
      << "  audio_codec: " << sc.audio_codec << std::endl
      << "  audio_bitrate: " << sc.audio_bitrate << std::endl
      << "  main_gettimes_threshold: " << std::endl
      << "    TIME: " << sc.main_gettimes_threshold[sc.TIMETYPE_TIME] << std::endl
      << "    GETTIMEOFDAY: " << sc.main_gettimes_threshold[sc.TIMETYPE_GETTIMEOFDAY] << std::endl
      << "    CLOCK: " << sc.main_gettimes_threshold[sc.TIMETYPE_CLOCK] << std::endl
      << "    CLOCKGETTIME: " << sc.main_gettimes_threshold[sc.TIMETYPE_CLOCKGETTIME] << std::endl
      << "    SDLGETTICKS: " << sc.main_gettimes_threshold[sc.TIMETYPE_SDLGETTICKS] << std::endl
      << "    SDLGETPERFORMANCECOUNTER: " << sc.main_gettimes_threshold[sc.TIMETYPE_SDLGETPERFORMANCECOUNTER] << std::endl
      << "  sec_gettimes_threshold: " << std::endl
      << "    TIME: " << sc.sec_gettimes_threshold[sc.TIMETYPE_TIME] << std::endl
      << "    GETTIMEOFDAY: " << sc.sec_gettimes_threshold[sc.TIMETYPE_GETTIMEOFDAY] << std::endl
      << "    CLOCK: " << sc.sec_gettimes_threshold[sc.TIMETYPE_CLOCK] << std::endl
      << "    CLOCKGETTIME: " << sc.sec_gettimes_threshold[sc.TIMETYPE_CLOCKGETTIME] << std::endl
      << "    SDLGETTICKS: " << sc.sec_gettimes_threshold[sc.TIMETYPE_SDLGETTICKS] << std::endl
      << "    SDLGETPERFORMANCECOUNTER: " << sc.sec_gettimes_threshold[sc.TIMETYPE_SDLGETPERFORMANCECOUNTER] << std::endl
      << "  save_screenpixels: " << sc.save_screenpixels << std::endl
      << "  initial_time: " << sc.initial_time.tv_sec << " " << sc.initial_time.tv_nsec << std::endl
      << "  screen_width: " << sc.screen_width << std::endl
      << "  screen_height: " << sc.screen_height << std::endl
      << "  incremental_savestates: " << sc.incremental_savestates << std::endl
      << "  savestates_in_ram: " << sc.savestates_in_ram << std::endl
      << "  backtrack_savestate: " << sc.backtrack_savestate << std::endl
      << "  debug_state: " << sc.debug_state << std::endl
      << "  recycle_threads: " << sc.recycle_threads << std::endl
      << "  locale: " << sc.locale << std::endl
      << "  virtual_steam: " << sc.virtual_steam << std::endl
      << "  opengl_soft: " << sc.opengl_soft << std::endl
      << "  async_events: " << sc.async_events << std::endl
      << "  wait_timeout: " << sc.wait_timeout << std::endl;
}


